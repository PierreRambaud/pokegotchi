#include "lv_i18n.h"
#include "Utils.h"
#include "keyboard_hal.h"
#include "GameSwitcher.h"
#include "DrawingBoard.h"

using namespace DrawingBoard;

LV_IMG_DECLARE(object_berry)
LV_IMG_DECLARE(object_apple)
LV_IMG_DECLARE(object_candy_box)
LV_IMG_DECLARE(ball_poke)
LV_IMG_DECLARE(stone_thunder)
LV_IMG_DECLARE(stone_fire)
LV_IMG_DECLARE(emote_heart)
LV_IMG_DECLARE(game_poo)

#define SCREEN_W 320
#define SCREEN_H 240
#define CANVAS_H 200
#define TOOL_SIZE 28
#define TOOL_GAP 4

// Drawing is relaxing: a small reward for the Pokemon
#define DRAWING_REWARD 3

static const uint8_t BRUSH_SIZES[] = {2, 5, 9, 15};
static const uint8_t BRUSH_SIZES_COUNT = sizeof(BRUSH_SIZES) / sizeof(BRUSH_SIZES[0]);

// The last swatch is the rainbow brush
static const uint32_t COLORS[DRAWINGBOARD_COLORS - 1] = {0x202020, 0xE53935, 0xFB8C00, 0xFDD835, 0x43A047, 0x1E88E5, 0x8E24AA};

static const lv_image_dsc_t* const STAMPS[] = {&object_berry, &object_apple, &ball_poke, &emote_heart, &stone_thunder, &stone_fire, &object_candy_box, &game_poo};
static const uint8_t STAMPS_COUNT = sizeof(STAMPS) / sizeof(STAMPS[0]);

static const lv_color_t PAPER = LV_COLOR_MAKE(0xFF, 0xFF, 0xFF);

Runner::Runner(void) {
  _screen = lv_obj_create(NULL);
  lv_obj_remove_style_all(_screen);
  lv_obj_set_size(_screen, SCREEN_W, SCREEN_H);
  lv_obj_set_style_bg_color(_screen, lv_color_make(60, 60, 70), 0);
  lv_obj_set_style_bg_opa(_screen, LV_OPA_COVER, 0);
  lv_obj_remove_flag(_screen, LV_OBJ_FLAG_SCROLLABLE);

  // Big buffers: in PSRAM on the device
  _buffer = lv_draw_buf_create(SCREEN_W, CANVAS_H, LV_COLOR_FORMAT_RGB565, 0);
  _undo_buffer = lv_draw_buf_create(SCREEN_W, CANVAS_H, LV_COLOR_FORMAT_RGB565, 0);
  if (_buffer == nullptr || _undo_buffer == nullptr) {
    // Not enough memory: back to the Pokemon at the first loop
    serial_printf("DrawingBoard", "Not enough memory for the canvas");
    lv_screen_load_anim(_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0, true);
    return;
  }

  _canvas = lv_canvas_create(_screen);
  lv_canvas_set_draw_buf(_canvas, _buffer);
  lv_canvas_fill_bg(_canvas, PAPER, LV_OPA_COVER);
  lv_obj_set_pos(_canvas, 0, 0);
  lv_obj_add_flag(_canvas, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_remove_flag(_canvas, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
  lv_obj_add_event_cb(_canvas, canvas_event_cb, LV_EVENT_ALL, this);

  create_toolbar();

  _message = lv_label_create(_screen);
  lv_obj_set_style_text_font(_message, &pokemon_font_12, 0);
  lv_obj_set_style_text_color(_message, lv_color_white(), 0);
  lv_obj_set_style_text_align(_message, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_bg_color(_message, lv_color_black(), 0);
  lv_obj_set_style_bg_opa(_message, LV_OPA_70, 0);
  lv_obj_set_style_pad_all(_message, 6, 0);
  lv_obj_set_style_radius(_message, 8, 0);
  lv_obj_set_width(_message, SCREEN_W - 40);
  lv_label_set_long_mode(_message, LV_LABEL_LONG_WRAP);
  lv_obj_align(_message, LV_ALIGN_TOP_MID, 0, 8);
  lv_obj_remove_flag(_message, LV_OBJ_FLAG_CLICKABLE);
  show_message(_("game.draw.help"), 4000);

  // Load it and delete the screen of the Pokemon, already emptied
  lv_screen_load_anim(_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0, true);
  update_toolbar();
}

Runner::~Runner(void) { close(); }

void Runner::close(void) {
  // The canvas must not draw from freed buffers
  if (_canvas != nullptr) {
    lv_obj_delete(_canvas);
    _canvas = nullptr;
  }

  if (_buffer != nullptr) {
    lv_draw_buf_destroy(_buffer);
    _buffer = nullptr;
  }

  if (_undo_buffer != nullptr) {
    lv_draw_buf_destroy(_undo_buffer);
    _undo_buffer = nullptr;
  }
}

/**
 * Bottom bar: the colors, the rainbow brush, the eraser and the stamps
 */
void Runner::create_toolbar(void) {
  int32_t x = (SCREEN_W - DRAWINGBOARD_TOOLS * TOOL_SIZE - (DRAWINGBOARD_TOOLS - 1) * TOOL_GAP) / 2;
  int32_t y = CANVAS_H + (SCREEN_H - CANVAS_H - TOOL_SIZE) / 2;

  for (uint8_t i = 0; i < DRAWINGBOARD_TOOLS; i++) {
    lv_obj_t* tool = lv_obj_create(_screen);
    lv_obj_remove_style_all(tool);
    lv_obj_set_size(tool, TOOL_SIZE, TOOL_SIZE);
    lv_obj_set_pos(tool, x + i * (TOOL_SIZE + TOOL_GAP), y);
    lv_obj_set_style_radius(tool, 6, 0);
    lv_obj_set_style_bg_opa(tool, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(tool, 2, 0);
    lv_obj_set_style_border_color(tool, lv_color_make(30, 30, 35), 0);
    lv_obj_add_flag(tool, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(tool, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(tool, tool_event_cb, LV_EVENT_CLICKED, this);

    if (i < DRAWINGBOARD_COLORS - 1) {
      lv_obj_set_style_bg_color(tool, lv_color_hex(COLORS[i]), 0);
    } else if (i == DRAWINGBOARD_COLORS - 1) {
      // Rainbow swatch
      lv_obj_set_style_bg_color(tool, lv_color_hex(0xE53935), 0);
      lv_obj_set_style_bg_grad_color(tool, lv_color_hex(0x1E88E5), 0);
      lv_obj_set_style_bg_main_stop(tool, 40, 0);
      lv_obj_set_style_bg_grad_dir(tool, LV_GRAD_DIR_VER, 0);
    } else if (i == DRAWINGBOARD_COLORS) {
      // Eraser: a piece of white paper with a pink end
      lv_obj_set_style_bg_color(tool, PAPER, 0);
      lv_obj_set_style_bg_grad_color(tool, lv_color_make(240, 130, 160), 0);
      lv_obj_set_style_bg_main_stop(tool, 150, 0);
      lv_obj_set_style_bg_grad_stop(tool, 160, 0);
      lv_obj_set_style_bg_grad_dir(tool, LV_GRAD_DIR_HOR, 0);
    } else {
      // Stamps: shows the current one
      lv_obj_set_style_bg_color(tool, lv_color_make(250, 240, 210), 0);
      _stamp_icon = lv_image_create(tool);
      lv_obj_center(_stamp_icon);
      lv_obj_remove_flag(_stamp_icon, LV_OBJ_FLAG_CLICKABLE);
    }

    _tools[i] = tool;
  }
}

void Runner::tool_event_cb(lv_event_t* e) {
  Runner* runner = (Runner*)lv_event_get_user_data(e);
  lv_obj_t* tool = lv_event_get_target_obj(e);
  for (uint8_t i = 0; i < DRAWINGBOARD_TOOLS; i++) {
    if (runner->_tools[i] == tool) {
      runner->select_tool(i);
    }
  }
}

void Runner::select_tool(uint8_t index) {
  if (index < DRAWINGBOARD_COLORS - 1) {
    _tool = TOOL_BRUSH;
    _color = index;
  } else if (index == DRAWINGBOARD_COLORS - 1) {
    _tool = TOOL_RAINBOW;
  } else if (index == DRAWINGBOARD_COLORS) {
    _tool = TOOL_ERASER;
  } else {
    // A second tap on the stamps picks the next one
    if (_tool == TOOL_STAMP) {
      _stamp = (_stamp + 1) % STAMPS_COUNT;
    }
    _tool = TOOL_STAMP;
  }

  _selected = index;
  update_toolbar();
}

/**
 * Highlight the selected tool, and show the current stamp
 */
void Runner::update_toolbar(void) {
  for (uint8_t i = 0; i < DRAWINGBOARD_TOOLS; i++) {
    bool selected = i == _selected;
    lv_obj_set_style_border_color(_tools[i], selected ? lv_color_white() : lv_color_make(30, 30, 35), 0);
    lv_obj_set_style_border_width(_tools[i], selected ? 3 : 2, 0);
    lv_obj_set_style_translate_y(_tools[i], selected ? -3 : 0, 0);
  }

  const lv_image_dsc_t* stamp = STAMPS[_stamp];
  lv_image_set_src(_stamp_icon, stamp);
  uint32_t largest = LV_MAX(stamp->header.w, stamp->header.h);
  lv_image_set_scale(_stamp_icon, 256 * (TOOL_SIZE - 8) / largest);
}

void Runner::show_message(const char* text, uint32_t duration_ms) {
  lv_label_set_text(_message, text);
  lv_obj_remove_flag(_message, LV_OBJ_FLAG_HIDDEN);
  _message_until = hal_millis() + duration_ms;
}

void Runner::save_undo(void) {
  lv_memcpy(_undo_buffer->data, _buffer->data, _buffer->data_size);
  _can_undo = true;
}

/**
 * Back to before the last stroke, stamp or clear. Undo again to redo.
 */
void Runner::undo(void) {
  if (!_can_undo) {
    return;
  }

  // Swap the two pictures
  uint8_t* current = _buffer->data;
  uint8_t* previous = _undo_buffer->data;
  for (uint32_t i = 0; i < _buffer->data_size; i++) {
    uint8_t byte = current[i];
    current[i] = previous[i];
    previous[i] = byte;
  }
  lv_obj_invalidate(_canvas);
}

void Runner::clear(void) {
  save_undo();
  lv_canvas_fill_bg(_canvas, PAPER, LV_OPA_COVER);
}

void Runner::change_size(void) {
  _size = (_size + 1) % BRUSH_SIZES_COUNT;

  char text[32];
  lv_snprintf(text, sizeof(text), _("game.draw.size"), _size + 1);
  show_message(text, 1000);
}

lv_color_t Runner::brush_color(void) {
  switch (_tool) {
    case TOOL_ERASER:
      return PAPER;
    case TOOL_RAINBOW:
      return lv_color_hsv_to_rgb(_hue, 90, 95);
    default:
      return lv_color_hex(COLORS[_color]);
  }
}

void Runner::canvas_event_cb(lv_event_t* e) {
  Runner* runner = (Runner*)lv_event_get_user_data(e);
  lv_event_code_t code = lv_event_get_code(e);
  lv_indev_t* indev = lv_indev_active();
  if (indev == NULL) {
    return;
  }

  lv_point_t point;
  lv_indev_get_point(indev, &point);
  point.y = LV_MIN(point.y, CANVAS_H - 1);

  if (code == LV_EVENT_PRESSED) {
    runner->stroke_start(point);
  } else if (code == LV_EVENT_PRESSING) {
    runner->stroke_move(point);
  } else if (code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST) {
    runner->_drawing = false;
  }
}

void Runner::stroke_start(lv_point_t point) {
  // Hide the help as soon as the child draws
  lv_obj_add_flag(_message, LV_OBJ_FLAG_HIDDEN);
  save_undo();

  if (_tool == TOOL_STAMP) {
    draw_stamp(point);
    return;
  }

  _drawing = true;
  _last_point = point;
  draw_segment(point, point);
}

void Runner::stroke_move(lv_point_t point) {
  if (!_drawing || (point.x == _last_point.x && point.y == _last_point.y)) {
    return;
  }

  draw_segment(_last_point, point);
  _last_point = point;
}

/**
 * A line between two touch points: fast strokes stay continuous
 */
void Runner::draw_segment(lv_point_t from, lv_point_t to) {
  uint8_t width = BRUSH_SIZES[_size] * (_tool == TOOL_ERASER ? 2 : 1);

  lv_layer_t layer;
  lv_canvas_init_layer(_canvas, &layer);

  if (from.x == to.x && from.y == to.y) {
    // A dot
    lv_draw_rect_dsc_t dot;
    lv_draw_rect_dsc_init(&dot);
    dot.bg_color = brush_color();
    dot.radius = LV_RADIUS_CIRCLE;
    lv_area_t area = {(int32_t)(from.x - width / 2), (int32_t)(from.y - width / 2), (int32_t)(from.x + width / 2), (int32_t)(from.y + width / 2)};
    lv_draw_rect(&layer, &dot, &area);
  } else {
    lv_draw_line_dsc_t line;
    lv_draw_line_dsc_init(&line);
    line.color = brush_color();
    line.width = width;
    line.round_start = 1;
    line.round_end = 1;
    line.p1.x = from.x;
    line.p1.y = from.y;
    line.p2.x = to.x;
    line.p2.y = to.y;
    lv_draw_line(&layer, &line);
  }

  lv_canvas_finish_layer(_canvas, &layer);

  // The rainbow goes around with the length of the stroke
  if (_tool == TOOL_RAINBOW) {
    int32_t distance = LV_ABS(to.x - from.x) + LV_ABS(to.y - from.y);
    _hue = (_hue + 2 + distance) % 360;
  }
}

void Runner::draw_stamp(lv_point_t point) {
  const lv_image_dsc_t* stamp = STAMPS[_stamp];

  lv_layer_t layer;
  lv_canvas_init_layer(_canvas, &layer);

  lv_draw_image_dsc_t image;
  lv_draw_image_dsc_init(&image);
  image.src = stamp;
  lv_area_t area = {(int32_t)(point.x - stamp->header.w / 2), (int32_t)(point.y - stamp->header.h / 2), 0, 0};
  area.x2 = area.x1 + stamp->header.w - 1;
  area.y2 = area.y1 + stamp->header.h - 1;
  lv_draw_image(&layer, &image, &area);

  lv_canvas_finish_layer(_canvas, &layer);
  hal_beep(1600, 30);
}

void Runner::loop(void) {
  if (_canvas == nullptr || hal_button_c_held()) {
    GameSwitcher::Runner::getInstance()->finish_minigame(DRAWING_REWARD);
    return;
  }

  if (hal_button_a_pressed()) {
    undo();
  } else if (hal_button_b_pressed()) {
    change_size();
  } else if (hal_button_c_clicked()) {
    clear();
  }

  if (_message_until != 0 && hal_millis() > _message_until) {
    _message_until = 0;
    lv_obj_add_flag(_message, LV_OBJ_FLAG_HIDDEN);
  }
}
