// By Ponticelli Domenico.
// 12NOV2020 Added touch screen support for M5Core2 By Zontex
// https://github.com/pcelli85/M5Stack_FlappyBird_game
#pragma once
#ifndef FLOPPYBIRD_RUNNER
#define FLOPPYBIRD_RUNNER

#include <M5Core2.h>
#include <EEPROM.h>
#include <GameInterface.h>

#define TFTW 320   // screen width
#define TFTH 240   // screen height
#define TFTW2 160  // half screen width
#define TFTH2 120  // half screen height
// game constant
#define SPEED 1
#define GRAVITY 9.8
#define JUMP_FORCE 2.15
#define SKIP_TICKS 20.0  // 1000 / 50fps
#define MAX_FRAMESKIP 5
// bird size
#define BIRDW 16  // bird width
#define BIRDH 16  // bird height
#define BIRDW2 8  // half width
#define BIRDH2 8  // half height
// pipe size
#define PIPEW 24      // pipe width
#define GAPHEIGHT 72  // pipe gap height
// floor size
#define FLOORH 30  // floor height (from bottom of the screen)
// grass size
#define GRASSH 4  // grass height (inside floor, starts at floor y)

// bird sprite
// bird sprite colors (Cx name for values to keep the array readable)
#define C0 BCKGRDCOL
#define C1 M5.Lcd.color565(195, 165, 75)
#define C2 BIRDCOL
#define C3 TFT_WHITE
#define C4 TFT_RED
#define C5 M5.Lcd.color565(251, 216, 114)

// ---------------
// draw pixel
// ---------------
// faster drawPixel method by inlining calls and using setAddrWindow and pushColor
// using macro to force inlining
#define drawPixel(a, b, c)          \
  M5.Lcd.setAddrWindow(a, b, a, b); \
  M5.Lcd.pushColor(c)

// background
const unsigned int BCKGRDCOL = M5.Lcd.color565(138, 235, 244);
// bird
const unsigned int BIRDCOL = M5.Lcd.color565(255, 254, 174);
// pipe
const unsigned int PIPECOL = M5.Lcd.color565(99, 255, 78);
// pipe highlight
const unsigned int PIPEHIGHCOL = M5.Lcd.color565(250, 255, 250);
// pipe seam
const unsigned int PIPESEAMCOL = M5.Lcd.color565(0, 0, 0);
// floor
const unsigned int FLOORCOL = M5.Lcd.color565(246, 240, 163);
// grass (col2 is the stripe color)
const unsigned int GRASSCOL = M5.Lcd.color565(141, 225, 87);
const unsigned int GRASSCOL2 = M5.Lcd.color565(156, 239, 88);

const int buttonPin = 2;

static unsigned int birdcol[] = {C0, C0, C1, C1, C1, C1, C1, C0, C0, C0, C1, C1, C1, C1, C1, C0, C0, C1, C2, C2, C2, C1, C3, C1, C0, C1, C2, C2, C2, C1, C3, C1,
                                 C0, C2, C2, C2, C2, C1, C3, C1, C0, C2, C2, C2, C2, C1, C3, C1, C1, C1, C1, C2, C2, C3, C1, C1, C1, C1, C1, C2, C2, C3, C1, C1,
                                 C1, C2, C2, C2, C2, C2, C4, C4, C1, C2, C2, C2, C2, C2, C4, C4, C1, C2, C2, C2, C1, C5, C4, C0, C1, C2, C2, C2, C1, C5, C4, C0,
                                 C0, C1, C2, C1, C5, C5, C5, C0, C0, C1, C2, C1, C5, C5, C5, C0, C0, C0, C1, C5, C5, C5, C0, C0, C0, C0, C1, C5, C5, C5, C0, C0};

// bird structure
static struct BIRD {
  long x, y, old_y;
  long col;
  float vel_y;
} bird;

// pipe structure
static struct PIPES {
  long x, gap_y;
  long col;
} pipes;

namespace FloppyBird {
  class Runner : public GameSwitcher::GameInterface {
   public:
    explicit Runner();

    void loop();

   private:
    void game_init();
    void game_start();
    void game_loop();
    void game_over();
    void resetMaxScore();

    int address = 0;
    int maxScore = EEPROM.readInt(address);
    int score = 0;
  };
}  // namespace FloppyBird
#endif
