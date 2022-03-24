#pragma once
#ifndef DRAWINGBOARD_RUNNER
#define DRAWINGBOARD_RUNNER

#include <lvgl.h>
#include <GameInterface.h>

namespace DrawingBoard {
  class Runner : public GameSwitcher::GameInterface {
   public:
    explicit Runner();
    void clear();
    void loop();

   protected:
    int8_t _size;
    int8_t _color;
    int8_t _clear_color;

    lv_obj_t* _color_label;
    lv_obj_t* _size_label;
    lv_obj_t* _clear_label;

    int32_t getColor(int8_t);
    void changeColor();
    void changeSize();
    void drawPoint(int32_t x, int32_t y);

    void drawPoints();
    void drawPoint();
  };
}  // namespace DrawingBoard
#endif
