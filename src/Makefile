CC=gcc
CFLAGS=-c -g -Wall -Werror -Wextra

BUILD_PATH=../build
NAME_1=state_sort
NAME_2=state_search
NAME_3=clear_state

EXE_1=Quest_1
EXE_2=Quest_2
EXE_3=Quest_3

SOURCES_1=bd.c sort.c state_sort.c io_common.c
SOURCES_2=bd.c sort.c state_search.c io_common.c
SOURCES_3=bd.c sort.c clear_state.c io_common.c
OBJECTS_1=$(SOURCES_1:.c=.o)
OBJECTS_2=$(SOURCES_2:.c=.o)
OBJECTS_3=$(SOURCES_3:.c=.o)

all: $(NAME_1) $(NAME_2) $(NAME_3)

$(NAME_1): $(BUILD_PATH)/$(EXE_1)

$(NAME_2): $(BUILD_PATH)/$(EXE_2)

$(NAME_3): $(BUILD_PATH)/$(EXE_3)

$(BUILD_PATH)/$(EXE_1): Makefile $(OBJECTS_1) main.h
	$(CC) $(OBJECTS_1) -o $(BUILD_PATH)/$(EXE_1)

$(BUILD_PATH)/$(EXE_2): Makefile $(OBJECTS_2) main.h
	$(CC) $(OBJECTS_2) -o $(BUILD_PATH)/$(EXE_2)

$(BUILD_PATH)/$(EXE_3): Makefile $(OBJECTS_3) main.h
	$(CC) $(OBJECTS_3) -o $(BUILD_PATH)/$(EXE_3)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(BUILD_PATH)/$(EXE_1) $(BUILD_PATH)/$(EXE_2) $(BUILD_PATH)/$(EXE_3)

rebuild: fclean all

run_1: $(BUILD_PATH)/$(EXE_1)
	$(BUILD_PATH)/$(EXE_1)

run_2: $(BUILD_PATH)/$(EXE_2)
	$(BUILD_PATH)/$(EXE_2)

run_3: $(BUILD_PATH)/$(EXE_3)
	$(BUILD_PATH)/$(EXE_3)

.PHONY: all clean fclean rebuild run_1 run_2 run_3 $(NAME_1) $(NAME_2) $(NAME_3)
