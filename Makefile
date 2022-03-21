APP_NAME = spichki
LIB_NAME = libspichki

CC = g++

CFLAGS = -Wall -Wextra -Werror
LFLAGS = -I src -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.cpp')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.cpp')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all clean

all: $(APP_PATH)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ 

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

clean:
	$(RM) $(APP_PATH) $(LIB_PATH) 
	find $(OBJ_DIR) -name '.[od]' -exec $(RM) '{}' \;

-include $(DEPS)
