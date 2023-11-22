SRC_DIRS := lib

# Fichiers source (C++ uniquement)
SRC_FILES := $(shell find $(SRC_DIRS) -name "*.cpp" -o -name "*.h")

# Exécutable Clang Format
CLANG_FORMAT := clang-format

format: $(SRC_FILES)
	$(CLANG_FORMAT) -i -style=file $^

build:
	pio run

upload:
	pio run -t upload

uploadfs:
	pio run -t uploadfs

install:
	npm i lv_i18n -g

i18n-extract:
	lv_i18n extract -s 'lib/**/*.+(c|cpp|h|hpp)' -t 'translations/*.yml'

i18n-compile:
	lv_i18n compile -t 'translations/*.yml' -o 'lib/lv_i18n'
