#pragma once
#ifndef DRAWINGBOARD_RUNNER
#define DRAWINGBOARD_RUNNER

#include "lvgl.h"
#include "GameInterface.h"

namespace DrawingBoard {
  class Runner : public GameSwitcher::GameInterface {
   public:
    explicit Runner(void);
    void clear(void);
    void loop(void);
    void close();

   protected:
    uint8_t _size;
    uint8_t _color;
    uint8_t _clear_color;

    lv_obj_t* _color_label;
    lv_obj_t* _size_label;
    lv_obj_t* _clear_label;

    uint32_t getColor(uint8_t);
    uint16_t getColorRGB565(uint8_t);
    void changeColor(void);
    void changeSize(void);
    void drawPoint(uint32_t x, uint32_t y);
    void drawPoints(void);
  };
}  // namespace DrawingBoard
#endif
