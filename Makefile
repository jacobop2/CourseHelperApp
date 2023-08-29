# Makefile for C++ program

# Compiler
CXX := clang++
# Compiler flags
CXXFLAGS := -std=c++14 -Wall
# Source files directory
SRC_DIR := src
# Output directory
BUILD_DIR := build
# Output executable name
EXECUTABLE := main

# List of source files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
# List of object files
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Check the platform
ifeq ($(OS),Windows_NT)
    # Windows settings
    RM := del /Q
    MKDIR := mkdir
    EXECUTABLE := $(EXECUTABLE).exe
else
    # macOS and Linux settings
    RM := rm -f
    MKDIR := mkdir -p
endif

# Targets
all: $(BUILD_DIR) $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

$(BUILD_DIR)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXECUTABLE)

.PHONY: all clean
