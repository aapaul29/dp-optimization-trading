CXX = g++
CXXFLAGS = -O2 -std=c++17 -Iinclude

SRC_CPP = src/cpp/iterative_dp.cpp \
          src/cpp/memoized_dp.cpp \
          src/cpp/optimized_dp.cpp \
          benchmarks/benchmark.cpp

TARGET = dp_benchmark

all: $(TARGET)

$(TARGET): $(SRC_CPP)
	$(CXX) $(CXXFLAGS) $(SRC_CPP) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
