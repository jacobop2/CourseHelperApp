# Makefile for C++ program

# Compiler
CXX := clang++
# Compiler flags
CXXFLAGS := -std=c++17 -Wall -ggdb
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

# Directory for test source files
TEST_DIR := tests

# List of test source files
TEST_SOURCES := $(wildcard $(TEST_DIR)/*.cpp)

# Test executable name
TEST_EXECUTABLE := test_runner

# Check the platform
ifeq ($(OS),Windows_NT)
    # Windows settings
    RM := del
    RMDIR := rmdir /s /q
    MKDIR := mkdir
    EXECUTABLE := $(EXECUTABLE).exe
    TEST_EXECUTABLE := $(TEST_EXECUTABLE).exe
else
    # macOS and Linux settings
    RM := rm -f
    RMDIR := rm -rf
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

# Clean rule to remove generated files
clean:
	$(RMDIR) $(BUILD_DIR)

# Test compilation target
test: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_SOURCES) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I../include -I$(TEST_DIR) $(filter-out $(BUILD_DIR)/main.o,$^) -o $(TEST_EXECUTABLE)

.PHONY: all clean test