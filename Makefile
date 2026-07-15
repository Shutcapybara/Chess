CXX := g++
CATCH2_CFLAGS := $(shell pkg-config --cflags catch2 2>/dev/null)
CATCH2_LIBS := -lCatch2Main $(shell pkg-config --libs catch2 2>/dev/null)
CXXFLAGS := -std=c++20 -Wall -Wextra -I./Pieces $(CATCH2_CFLAGS)
SRC := $(wildcard *.cpp) $(wildcard Pieces/*.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := chess
TEST_SRC := $(wildcard tests/*.cpp)
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_TARGET := test_runner

.PHONY: all test clean

all: $(TARGET)

test: $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJ) $(filter-out main.o,$(OBJ))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(CATCH2_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET)

