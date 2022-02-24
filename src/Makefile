CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

BUILD_PATH=../build
NAME_1=Quest_1

DFLAGS= -D_DB_MODULES_PATH_="$(CURDIR)/../materials/master_modules.db" \
        -DDB_LEVELS_PATH_="$(CURDIR)/../materials/master_levels.db" \
        -D_DB_EVENTS_PATH_="$(CURDIR)/../materials/master_status_events.db"

EXE_1=Quest_1

SOURCES_1=bd.c \
          io_helper.c \
		  levels.c \
		  modules_db.c \
		  modules.c \
		  shared_connector.c \
		  shared.c \
		  status_events.c
OBJECTS_1=$(SOURCES_1:.c=.o)


all: $(NAME_1) $(NAME_2) $(NAME_3)

$(NAME_1): $(BUILD_PATH)/$(EXE_1)

$(BUILD_PATH)/$(EXE_1): Makefile $(OBJECTS_1) main.h
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
