BUILD_DIR="build"
ENGINE_OBJS=player.o game.o vector.o run.o
CFLAGS=-Wall -Werror -O
LIBS=-lpthread

default: text

text: text.o engine
	cd build; gcc ${CFLAGS} text.o ${ENGINE_OBJS} -o ../mobamobile ${LIBS}

engine: $(ENGINE_OBJS)

text.o:
	gcc ${CFLAGS} -c text/text.c -o $(BUILD_DIR)/text.o -I.

player.o:
	gcc ${CFLAGS} -c player/player.c -o $(BUILD_DIR)/player.o -I.

game.o:
	gcc ${CFLAGS} -c game/game.c -o $(BUILD_DIR)/game.o -I.

vector.o:
	gcc ${CFLAGS} -c math/vector.c -o $(BUILD_DIR)/vector.o -I.

run.o:
	gcc ${CFLAGS} -c run/run.c -o $(BUILD_DIR)/run.o -I.

clean:
	cd build; rm -f ${ENGINE_OBJS} text.o ../mobamobile
