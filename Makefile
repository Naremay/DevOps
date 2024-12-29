# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra

# Directories
BUILD_DIR = build
BIN_DIR = bin

# Files and targets
TARGET = $(BIN_DIR)/hyperbolic_series
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean

