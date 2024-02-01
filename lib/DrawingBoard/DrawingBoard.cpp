#include "M5Core2.h"
#include "lv_i18n.h"
#include "DrawingBoard.h"
#include "Utils.h"

using namespace DrawingBoard;

static lv_style_t style_color_label;
static lv_style_t style_size_label;
static lv_style_t style_clear_label;

Runner::Runner() {
  _size = 5;
  _color = 8;
  _clear_color = 0;


  M5.Lcd.fillScreen(getColor(BLACK)); // Set default background color to black

  lv_style_set_text_color(&style_color_label, lv_color_hex3(getColor(_color)));
  lv_style_set_text_color(&style_size_label, lv_color_white());
  lv_style_set_text_color(&style_clear_label, lv_color_white());

  lv_obj_t* main_screen = lv_obj_create(NULL);
  lv_screen_load(main_screen);
  lv_obj_remove_style_all(main_screen);
  lv_obj_set_size(main_screen, LV_HOR_RES_MAX, 20);
  lv_obj_set_pos(main_screen, 0, LV_VER_RES_MAX - 20);
  lv_obj_set_scrollbar_mode(main_screen, LV_SCROLLBAR_MODE_OFF);

  static lv_style_t flex_style;
  lv_style_set_flex_flow(&flex_style, LV_FLEX_FLOW_ROW_WRAP);
  lv_style_set_flex_main_place(&flex_style, LV_FLEX_ALIGN_SPACE_AROUND);
  lv_style_set_layout(&flex_style, LV_LAYOUT_FLEX);

  lv_obj_add_style(main_screen, &flex_style, 0);

  _color_label = lv_label_create(main_screen);
  lv_label_set_text(_color_label, _("game.draw.color"));
  lv_obj_add_style(_color_label, &style_color_label, 0);

  _size_label = lv_label_create(main_screen);
  lv_label_set_text_fmt(_size_label, _("game.draw.size"), _size);
  lv_obj_add_style(_size_label, &style_size_label, 0);

  _clear_label = lv_label_create(main_screen);
  lv_label_set_text(_clear_label, _("game.draw.clear"));
  lv_obj_add_style(_clear_label, &style_clear_label, 0);

  clear();
}

uint32_t Runner::getColor(uint8_t color) {
  switch (color) {
    case 0:
      return BLACK;
    case 1:
      return GREEN;
    case 2:
      return BLUE;
    case 3:
      return RED;
    case 4:
      return YELLOW;
    case 5:
      return PINK;
    case 6:
      return CYAN;
    case 7:
      return ORANGE;
    default:
      return WHITE;
  }
}

void Runner::drawPoint(uint32_t x, uint32_t y) {
  M5.Lcd.drawCircle(x, y, _size, getColor(_color));
  M5.Lcd.fillCircle(x, y, _size, getColor(_color));

  serial_printf("DrawingBoard", "Draw point: %d, %d\r\n", x, y);
}

void Runner::changeColor() {
  _color = _color + 1;
  if (_color > 8) {
    _color = 0;
  }

  lv_style_set_text_color(&style_color_label, lv_color_hex3(getColor(_color)));
  lv_obj_report_style_change(&style_color_label);

  serial_printf("DrawingBoard", "Color changed: %d\r\n", _color);
}

void Runner::changeSize() {
  _size = _size + 5;
  if (_size == 20) {
    _size = 5;
  }

  lv_label_set_text_fmt(_size_label, _("game.draw.size"), _size);
  serial_printf("DrawingBoard", "Size changed: %d\r\n", _size);
}

void Runner::drawPoints() {
  if (M5.Touch.ispressed() == false) {
    return;
  }

  TouchPoint_t coordinate = M5.Touch.getPressPoint();
  if (coordinate.y == -1 or coordinate.x == -1) {
    return;
  }

  if ((coordinate.y >= 220 - _size) == false) {
    drawPoint(coordinate.x, coordinate.y);
  }
}

void Runner::clear() {
  _clear_color = _clear_color + 1;
  if (_clear_color > 8) {
    _clear_color = 0;
  }

  M5.Lcd.fillScreen(getColor(_clear_color));
  lv_obj_report_style_change(&style_color_label);
  lv_obj_report_style_change(&style_clear_label);
  lv_label_set_text_fmt(_size_label, _("game.draw.size"), _size);
}

void Runner::loop() {
  if (M5.BtnA.wasPressed()) {
    changeColor();
  } else if (M5.BtnB.wasPressed()) {
    changeSize();
  } else if (M5.BtnC.wasPressed()) {
    clear();
  }

  drawPoints();
}
