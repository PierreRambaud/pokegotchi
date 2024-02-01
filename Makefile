SRC_DIRS := lib

SRC_FILES := $(shell find $(SRC_DIRS) -name "*.cpp" -o -name "*.h")
CLANG_FORMAT := clang-format
DEFAULT_ENV=$(if $(filter-out $@,$(MAKECMDGOALS)), -e $(filter-out $@,$(MAKECMDGOALS)), -e m5stack-core2)

format: $(SRC_FILES)
	$(CLANG_FORMAT) -i -style=file $^

build:
	pio run${DEFAULT_ENV}

monitor:
	pio device monitor

upload:
	pio run -t upload${DEFAULT_ENV}

uploadfs:
	pio run -t uploadfs${DEFAULT_ENV}

install:
	npm i lv_i18n -g

i18n-extract:
	lv_i18n extract -s 'lib/**/*.+(c|cpp|h|hpp)' -t 'translations/*.yml'

i18n-compile:
	lv_i18n compile -t 'translations/*.yml' -o 'lib/lv_i18n'

assets-background:
	find assets_source/background/*.png -type f -exec .pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=RGB888 --ofmt=C -o src/assets/background/ {} \;

assets-game:
	find assets_source/game/*.png -type f -exec .pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=C -o src/assets/game/ {} \;

assets-battery:
	find assets_source/battery/*.png -type f -exec .pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=BIN -o data/menu/battery/ {} \;

assets-home:
	.pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=C -o src/assets/home assets_source/home/home_title.png
	.pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=BIN -o data/home/ assets_source/home/eevee.png
	.pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=BIN -o data/home/ assets_source/home/pichu.png

assets-pokemon-face:
	find assets_source/pokemon/face/*.png -type f -exec .pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=BIN -o data/pokemon/face/ {} \;

assets-menu:
	find assets_source/menu/*.png -type f -exec .pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=C -o src/assets/menu/ {} \;

assets-object-bag:
	find assets_source/objects/bag/*.png -type f -exec .pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=C -o src/assets/objects/bag {} \;

assets-object-balls:
	find assets_source/objects/balls/*.png -type f -exec .pio/libdeps/m5stack-core2/lvgl/scripts/LVGLImage.py --cf=ARGB8888 --ofmt=C -o src/assets/objects/balls {} \;

%:
    @:
