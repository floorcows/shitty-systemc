CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -DIS_DEBUG_ON=0
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := output
INCLUDE  := -Iinclude/
SRC      :=                      \
    $(wildcard src/*.cpp)         \
#    $(wildcard src/module1/*.cpp) \
#    $(wildcard src/module2/*.cpp) \
   
OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES \
	:= $(OBJECTS:.o=.d)

all: build $(TARGET)

verbose: CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -DIS_DEBUG_ON=1
verbose: clean all

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
   @echo "[*] Application dir: ${APP_DIR}     "
   @echo "[*] Object dir:      ${OBJ_DIR}     "
   @echo "[*] Sources:         ${SRC}         "
   @echo "[*] Objects:         ${OBJECTS}     "
   @echo "[*] Dependencies:    ${DEPENDENCIES}"
