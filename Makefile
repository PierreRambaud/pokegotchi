install:
	npm i littlevgl/lv_i18n -g

i18n-extract:
	lv_i18n extract -s 'lib/**/*.+(c|cpp|h|hpp)' -t 'translations/*.yml'

i18n-compile:
	compile -t 'translations/*.yml' -o 'lib/lv_i18n'
