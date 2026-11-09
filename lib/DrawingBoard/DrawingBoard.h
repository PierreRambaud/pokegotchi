#pragma once
#ifndef DRAWINGBOARD_RUNNER
#define DRAWINGBOARD_RUNNER

#include "lvgl.h"
#include "GameInterface.h"

#define DRAWINGBOARD_COLORS 8
#define DRAWINGBOARD_TOOLS (DRAWINGBOARD_COLORS + 2)

namespace DrawingBoard {
  enum Tool : uint8_t { TOOL_BRUSH, TOOL_RAINBOW, TOOL_ERASER, TOOL_STAMP };

  /**
   * Draw with the finger on a canvas: colors, a rainbow brush, an eraser and
   * Pokemon stamps. A: undo, B: brush size, C: clear, hold C: back.
   * Built with LVGL, so it runs on the device and on the emulator.
   */
  class Runner : public GameSwitcher::GameInterface {
   public:
    explicit Runner(void);
    ~Runner(void);

    void loop(void);
    void close(void);

   private:
    void create_toolbar(void);
    void select_tool(uint8_t index);
    void update_toolbar(void);
    void save_undo(void);
    void undo(void);
    void clear(void);
    void change_size(void);
    void show_message(const char* text, uint32_t duration_ms);

    void stroke_start(lv_point_t point);
    void stroke_move(lv_point_t point);
    void draw_segment(lv_point_t from, lv_point_t to);
    void draw_stamp(lv_point_t point);
    lv_color_t brush_color(void);

    static void canvas_event_cb(lv_event_t* e);
    static void tool_event_cb(lv_event_t* e);

    lv_obj_t* _screen;
    lv_obj_t* _canvas = nullptr;
    lv_obj_t* _message;
    lv_obj_t* _tools[DRAWINGBOARD_TOOLS];
    lv_obj_t* _stamp_icon;
    lv_draw_buf_t* _buffer = nullptr;
    lv_draw_buf_t* _undo_buffer = nullptr;
    bool _can_undo = false;

    Tool _tool = TOOL_BRUSH;
    uint8_t _selected = 0;
    uint8_t _color = 0;
    uint8_t _size = 1;
    uint8_t _stamp = 0;
    uint16_t _hue = 0;
    lv_point_t _last_point;
    bool _drawing = false;
    unsigned long _message_until = 0;
  };
}  // namespace DrawingBoard
#endif
