# PokeGotchi

Trying to provide a tamagotchi game for my daugther, based on little characters she likes.

Everything is done for the M5Core2 in C with [lvgl 8](https://github.com/lvgl/lvgl).

## Usage


### Build translations

```shell

$ make install
$ make i18n-extract
$ make i18n-compile
```

Watch out, because of Arduino dependency, you can't simply commit the changed file.
You have to change `_p` into `_pl` and make sure struct are correctly defined.

## Dependencies

 - [Arduino](https://github.com/arduino/Arduino)
 - [Pokemon font](https://github.com/PascalPixel/pokemon-font)
 - [lvgl 8](https://github.com/lvgl/lvgl)
 - [M5Core2](https://github.com/m5stack/M5Core2)
 - [PlatformIO](https://platformio.org/)

