BUILD_DIR="build"

default: text

text: text.o
	gcc -Wall -Werror -O $(BUILD_DIR)/text.o -o mobamobile

text.o:
	gcc -Wall -Werror -O -c text/text.c -o $(BUILD_DIR)/text.o
