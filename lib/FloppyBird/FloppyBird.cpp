#ifdef POKEGOTCHI_INCLUDE_GAMES
// By Ponticelli Domenico.
// And M5Stack Core team
// 12NOV2020 Added touch screen support for M5Core2 By Zontex
// Adapter from:
// https://github.com/m5stack/M5Core2/blob/master/examples/games/floppybird/floppybird.ino

#include "lv_i18n.h"
#include "FloppyBird.h"

using namespace FloppyBird;

// temporary x and y var
static short tmpx, tmpy;

void eventDisplay(Event& e);

Runner::Runner(void) {
  M5.Buttons.addHandler(eventDisplay, E_TOUCH);
  EEPROM.begin(1000);
  Serial.println("Last max score:");
  Serial.println(EEPROM.readInt(address));
}

void Runner::loop(void) {
  // put your main code here, to run repeatedly:
  game_start();
  game_loop();
  game_over();
}

// ---------------
// game loop
// ---------------
void Runner::game_loop(void) {
  // ===============
  // prepare game variables
  // draw floor
  // ===============
  // instead of calculating the distance of the floor from the screen height each time store it in a variable
  unsigned char GAMEH = TFTH - FLOORH;
  // draw the floor once, we will not overwrite on this area in-game
  // black line
  M5.Lcd.drawFastHLine(0, GAMEH, TFTW, TFT_BLACK);
  // grass and stripe
  M5.Lcd.fillRect(0, GAMEH + 1, TFTW2, GRASSH, GRASSCOL);
  M5.Lcd.fillRect(TFTW2, GAMEH + 1, TFTW2, GRASSH, GRASSCOL2);
  // black line
  M5.Lcd.drawFastHLine(0, GAMEH + GRASSH, TFTW, TFT_BLACK);
  // mud
  M5.Lcd.fillRect(0, GAMEH + GRASSH + 1, TFTW, FLOORH - GRASSH, FLOORCOL);
  // grass x position (for stripe animation)
  long grassx = TFTW;
  // game loop time variables
  double delta, old_time, next_game_tick, current_time;
  next_game_tick = current_time = millis();
  // passed pipe flag to count score
  bool passed_pipe = false;
  // temp var for setAddrWindow
  unsigned char px;

  while (1) {
    int loops = 0;
    while (millis() > next_game_tick && loops < MAX_FRAMESKIP) {
      // ===============
      // input
      // ===============
      M5.update();

      // ===============
      // update
      // ===============
      // calculate delta time
      // ---------------
      old_time = current_time;
      current_time = millis();
      delta = (current_time - old_time) / 1000;

      // bird
      // ---------------
      bird.vel_y += GRAVITY * delta;
      bird.y += bird.vel_y;

      // pipe
      // ---------------
      pipes.x -= SPEED;
      // if pipe reached edge of the screen reset its position and gap
      if (pipes.x < -PIPEW) {
        pipes.x = TFTW;
        pipes.gap_y = random(10, GAMEH - (10 + GAPHEIGHT));
      }

      // ---------------
      next_game_tick += SKIP_TICKS;
      loops++;
    }

    // ===============
    // draw
    // ===============
    // pipe
    // ---------------
    // we save cycles if we avoid drawing the pipe when outside the screen
    if (pipes.x >= 0 && pipes.x < TFTW) {
      // pipe color
      M5.Lcd.drawFastVLine(pipes.x + 3, 0, pipes.gap_y, PIPECOL);
      M5.Lcd.drawFastVLine(pipes.x + 3, pipes.gap_y + GAPHEIGHT + 1, GAMEH - (pipes.gap_y + GAPHEIGHT + 1), PIPECOL);
      // highlight
      M5.Lcd.drawFastVLine(pipes.x, 0, pipes.gap_y, PIPEHIGHCOL);
      M5.Lcd.drawFastVLine(pipes.x, pipes.gap_y + GAPHEIGHT + 1, GAMEH - (pipes.gap_y + GAPHEIGHT + 1), PIPEHIGHCOL);
      // bottom and top border of pipe
      drawPixel(pipes.x, pipes.gap_y, PIPESEAMCOL);
      drawPixel(pipes.x, pipes.gap_y + GAPHEIGHT, PIPESEAMCOL);
      // pipe seam
      drawPixel(pipes.x, pipes.gap_y - 6, PIPESEAMCOL);
      drawPixel(pipes.x, pipes.gap_y + GAPHEIGHT + 6, PIPESEAMCOL);
      drawPixel(pipes.x + 3, pipes.gap_y - 6, PIPESEAMCOL);
      drawPixel(pipes.x + 3, pipes.gap_y + GAPHEIGHT + 6, PIPESEAMCOL);
    }
    // erase behind pipe
    if (pipes.x <= TFTW) M5.Lcd.drawFastVLine(pipes.x + PIPEW, 0, GAMEH, BCKGRDCOL);

    // bird
    // ---------------
    tmpx = BIRDW - 1;
    do {
      px = bird.x + tmpx + BIRDW;
      // clear bird at previous position stored in old_y
      // we can't just erase the pixels before and after current position
      // because of the non-linear bird movement (it would leave 'dirty' pixels)
      tmpy = BIRDH - 1;
      do {
        drawPixel(px, bird.old_y + tmpy, BCKGRDCOL);
      } while (tmpy--);
      // draw bird sprite at new position
      tmpy = BIRDH - 1;
      do {
        drawPixel(px, bird.y + tmpy, birdcol[tmpx + (tmpy * BIRDW)]);
      } while (tmpy--);
    } while (tmpx--);
    // save position to erase bird on next draw
    bird.old_y = bird.y;

    // grass stripes
    // ---------------
    grassx -= SPEED;
    if (grassx < 0) grassx = TFTW;
    M5.Lcd.drawFastVLine(grassx % TFTW, GAMEH + 1, GRASSH - 1, GRASSCOL);
    M5.Lcd.drawFastVLine((grassx + 64) % TFTW, GAMEH + 1, GRASSH - 1, GRASSCOL2);

    // ===============
    // collision
    // ===============
    // if the bird hit the ground game over
    if (bird.y > GAMEH - BIRDH) break;
    // checking for bird collision with pipe
    if (bird.x + BIRDW >= pipes.x - BIRDW2 && bird.x <= pipes.x + PIPEW - BIRDW) {
      // bird entered a pipe, check for collision
      if (bird.y < pipes.gap_y || bird.y + BIRDH > pipes.gap_y + GAPHEIGHT)
        break;
      else
        passed_pipe = true;
    }
    // if bird has passed the pipe increase score
    else if (bird.x > pipes.x + PIPEW - BIRDW && passed_pipe) {
      passed_pipe = false;
      // erase score with background color
      M5.Lcd.setTextColor(BCKGRDCOL);
      M5.Lcd.setCursor(TFTW2, 4);
      M5.Lcd.print(score);
      // set text color back to white for new score
      M5.Lcd.setTextColor(TFT_WHITE);
      // increase score since we successfully passed a pipe
      score++;
    }

    // update score
    // ---------------
    M5.Lcd.setCursor(TFTW2, 4);
    M5.Lcd.print(score);
  }

  // add a small delay to show how the player lost
  delay(1200);
}

void Runner::game_init(void) {
  // clear screen
  M5.Lcd.fillScreen(BCKGRDCOL);
  // reset score
  score = 0;
  // init bird
  bird.x = 144;
  bird.y = bird.old_y = TFTH2 - BIRDH;
  bird.vel_y = -JUMP_FORCE;
  tmpx = tmpy = 0;
  // generate new random seed for the pipe gape
  randomSeed(analogRead(0));
  // init pipe
  pipes.x = 0;
  pipes.gap_y = random(20, TFTH - 60);
}

// ---------------
// game start
// ---------------
void Runner::game_start(void) {
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.fillRect(10, TFTH2 - 20, TFTW - 20, 1, TFT_WHITE);
  M5.Lcd.fillRect(10, TFTH2 + 32, TFTW - 20, 1, TFT_WHITE);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setTextSize(3);
  // half width - num char * char width in pixels
  M5.Lcd.setCursor(TFTW2 - (6 * 9), TFTH2 - 16);
  M5.Lcd.println("FLOPPY");
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(TFTW2 - (6 * 9), TFTH2 + 8);
  M5.Lcd.println("-BIRD-");
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(TFTW2 - (M5.Lcd.textWidth(_("game.bird.start")) / 2), TFTH2 + 56);
  M5.Lcd.println(_("game.bird.start"));

  while (1) {
    // wait for push button
    if (M5.BtnB.wasPressed()) {
      break;
    }
    M5.update();
  }
  // init game settings
  game_init();
}

// ---------------
// game over
// ---------------
void Runner::game_over(void) {
  M5.Lcd.fillScreen(TFT_BLACK);
  maxScore = EEPROM.readInt(address);

  if (score > maxScore) {
    EEPROM.writeInt(address, score);
    EEPROM.commit();

    maxScore = score;

    M5.Lcd.setTextColor(TFT_RED);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(TFTW2 - (13 * 6), TFTH2 - 26);
    M5.Lcd.println(_("game.bird.highscore"));
  }

  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setTextSize(3);
  // half width - num char * char width in pixels
  M5.Lcd.setCursor(TFTW2 - (M5.Lcd.textWidth(_("game.bird.gameover")) / 2), TFTH2 - 6);
  M5.Lcd.println(_("game.bird.gameover"));
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.print(_("game.bird.score"));
  M5.Lcd.print(" ");
  M5.Lcd.print(score);
  M5.Lcd.setCursor(TFTW2 - ((M5.Lcd.textWidth(_("game.bird.restart")) / 2)), TFTH2 + 18);
  M5.Lcd.println(_("game.bird.restart"));
  M5.Lcd.setCursor(10, 28);
  M5.Lcd.print(_("game.bird.maxscore"));
  M5.Lcd.print(" ");
  M5.Lcd.print(maxScore);
  while (1) {
    // wait for push button
    if (M5.BtnB.wasPressed()) {
      break;
    }
    M5.update();
  }
}

void Runner::resetMaxScore(void) {
  EEPROM.writeInt(address, 0);
  EEPROM.commit();
}

void eventDisplay(Event& e) {
  // if the bird is not too close to the top of the screen apply jump force
  if (bird.y > BIRDH2 * 0.5) {
    bird.vel_y = -JUMP_FORCE;
  } else {
    // else zero velocity
    bird.vel_y = 0;
  }
}
#endif