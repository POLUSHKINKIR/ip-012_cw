APP_NAME = spichki
LIB_NAME = libspichki

CC = gcc

CFLAGS = -Wall -Wextra -Werror
LFLAGS = -I src -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test
THIRDPARTY_DIR = thirdparty

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.c')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_PATH = $(BIN_DIR)/$(APP_NAME)-test
TESTFLAGS = -I $(TEST_DIR) -I $(THIRDPARTY_DIR)

TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.c')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.c=$(OBJ_DIR)/$(TEST_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) 

.PHONY: all clean test

all: $(APP_PATH)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ 

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

test: all $(TEST_PATH)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $(TESTFLAGS) $^ -o $@ 

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(LFLAGS) $(TESTFLAGS) -c $< -o $@

clean:
	$(RM) $(APP_PATH) $(LIB_PATH) 
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;

-include $(DEPS)
