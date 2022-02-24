CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

BUILD_PATH=../build
NAME_1=Quest_1

DFLAGS= -D'_DB_MODULES_PATH_="$(CURDIR)/../materials/master_modules.db"' \
        -D'_DB_LEVELS_PATH_="$(CURDIR)/../materials/master_levels.db"' \
        -D'_DB_EVENTS_PATH_="$(CURDIR)/../materials/master_status_events.db"'

EXE_1=Quest_1

SOURCES_1=bd.c \
		  shared.c \
		  shared_connector.c \
          io_helper.c \
		  sequence.c \
		  modules_db.c \
		  levels.c \
		  modules.c \
		  status_events.c
OBJECTS_1=$(SOURCES_1:.c=.o)


all: $(NAME_1) $(NAME_2) $(NAME_3)

$(NAME_1): $(BUILD_PATH)/$(EXE_1)

$(BUILD_PATH)/$(EXE_1): Makefile $(OBJECTS_1) main.h
	mkdir -p $(BUILD_PATH)
	$(CC) $(OBJECTS_1) -o $(BUILD_PATH)/$(EXE_1)

%.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(BUILD_PATH)/$(EXE_1)

rebuild: fclean all

run_1: $(BUILD_PATH)/$(EXE_1)
	$(BUILD_PATH)/$(EXE_1)

.PHONY: all clean fclean rebuild run_1 $(NAME_1)
