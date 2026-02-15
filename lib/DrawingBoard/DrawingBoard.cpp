#ifdef POKEGOTCHI_INCLUDE_GAMES
#include <M5Unified.h>
#include "lv_i18n.h"
#include "DrawingBoard.h"
#include "Utils.h"

using namespace DrawingBoard;

static lv_style_t style_color_label;
static lv_style_t style_size_label;
static lv_style_t style_clear_label;

Runner::Runner(void) {
  _size = 5;
  _color = 8;
  _clear_color = 0;

  lv_style_init(&style_color_label);
  lv_style_init(&style_size_label);
  lv_style_init(&style_clear_label);

  lv_style_set_text_color(&style_color_label, lv_color_hex(getColor(_color)));
  lv_style_set_text_color(&style_size_label, lv_color_hex(0xFFFFFF));
  lv_style_set_text_color(&style_clear_label, lv_color_hex(0xFFFFFF));

  lv_obj_t* active_screen = lv_scr_act();

  lv_obj_t* label_container = lv_obj_create(active_screen);
  lv_obj_remove_style_all(label_container);

  lv_display_t* disp = lv_display_get_default();
  int32_t hor_res = lv_display_get_horizontal_resolution(disp);
  int32_t ver_res = lv_display_get_vertical_resolution(disp);

  lv_obj_set_size(label_container, hor_res, 20);
  lv_obj_align(label_container, LV_ALIGN_BOTTOM_MID, 0, 0);
  lv_obj_set_scrollbar_mode(label_container, LV_SCROLLBAR_MODE_OFF);

  lv_obj_set_style_bg_opa(label_container, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_set_style_bg_color(label_container, lv_color_hex(0x000000), LV_PART_MAIN);

  lv_obj_move_to_index(label_container, -1);

  static lv_style_t flex_style;
  lv_style_init(&flex_style);
  lv_style_set_flex_flow(&flex_style, LV_FLEX_FLOW_ROW_WRAP);
  lv_style_set_flex_main_place(&flex_style, LV_FLEX_ALIGN_SPACE_AROUND);
  lv_style_set_layout(&flex_style, LV_LAYOUT_FLEX);
  lv_obj_add_style(label_container, &flex_style, LV_PART_MAIN);

  _color_label = lv_label_create(label_container);
  lv_label_set_text(_color_label, _("game.draw.color"));
  lv_obj_add_style(_color_label, &style_color_label, LV_PART_MAIN);

  _size_label = lv_label_create(label_container);
  lv_label_set_text_fmt(_size_label, _("game.draw.size"), _size);
  lv_obj_add_style(_size_label, &style_size_label, LV_PART_MAIN);

  _clear_label = lv_label_create(label_container);
  lv_label_set_text(_clear_label, _("game.draw.clear"));
  lv_obj_add_style(_clear_label, &style_clear_label, LV_PART_MAIN);

  lv_refr_now(disp);

  uint16_t color565 = getColorRGB565(_clear_color);
  M5.Display.fillScreen(color565);
  M5.Display.waitDisplay();

  lv_obj_invalidate(label_container);
}

uint32_t Runner::getColor(uint8_t color) {
  switch (color) {
    case 0:
      return 0x000000;  // Black
    case 1:
      return 0x00FF00;  // Green
    case 2:
      return 0x0000FF;  // Blue
    case 3:
      return 0xFF0000;  // Red
    case 4:
      return 0xFFFF00;  // Yellow
    case 5:
      return 0xFF00FF;  // Magenta/Pink
    case 6:
      return 0x00FFFF;  // Cyan
    case 7:
      return 0xFF8000;  // Orange
    default:
      return 0xFFFFFF;  // White
  }
}

uint16_t Runner::getColorRGB565(uint8_t color) {
  uint32_t rgb888 = getColor(color);
  uint8_t r = (rgb888 >> 16) & 0xFF;
  uint8_t g = (rgb888 >> 8) & 0xFF;
  uint8_t b = rgb888 & 0xFF;
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

void Runner::drawPoint(uint32_t x, uint32_t y) {
  uint16_t color565 = getColorRGB565(_color);
  M5.Display.drawCircle(x, y, _size, color565);
  M5.Display.fillCircle(x, y, _size, color565);

  serial_printf("DrawingBoard", "Draw point: %d, %d\r\n", x, y);
}

void Runner::changeColor(void) {
  _color = _color + 1;
  if (_color > 8) {
    _color = 0;
  }

  lv_style_set_text_color(&style_color_label, lv_color_hex(getColor(_color)));
  lv_obj_invalidate(_color_label);

  serial_printf("DrawingBoard", "Color changed: %d\r\n", _color);
}

void Runner::changeSize(void) {
  _size = _size + 5;
  if (_size == 20) {
    _size = 5;
  }

  lv_label_set_text_fmt(_size_label, _("game.draw.size"), _size);
  serial_printf("DrawingBoard", "Size changed: %d\r\n", _size);
}

void Runner::drawPoints(void) {
  auto touch_count = M5.Touch.getCount();
  if (touch_count == 0) {
    return;
  }

  auto touch_detail = M5.Touch.getDetail();
  if (touch_detail.y == -1 || touch_detail.x == -1) {
    return;
  }

  if ((touch_detail.y >= 220 - _size) == false) {
    drawPoint(touch_detail.x, touch_detail.y);
  }
}

void Runner::clear(void) {
  _clear_color = _clear_color + 1;
  if (_clear_color > 8) {
    _clear_color = 0;
  }

  uint16_t color565 = getColorRGB565(_clear_color);
  M5.Display.fillScreen(color565);

  lv_obj_invalidate(_color_label);
  lv_obj_invalidate(_clear_label);
  lv_label_set_text_fmt(_size_label, _("game.draw.size"), _size);
}

void Runner::loop(void) {
  if (M5.BtnA.wasPressed()) {
    changeColor();
  } else if (M5.BtnB.wasPressed()) {
    changeSize();
  } else if (M5.BtnC.wasPressed()) {
    clear();
  }

  drawPoints();
}

void Runner::close() {}

#endif
