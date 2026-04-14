CXX = g++
CXXFLAGS = -O2 -std=c++17 -Iinclude
SRC = src/iterative_dp.cpp src/memoized_dp.cpp src/optimized_dp.cpp src/utils.cpp benchmarks/benchmark.cpp
BUILD_DIR = build
TARGET = $(BUILD_DIR)/dp_benchmark

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(TARGET)