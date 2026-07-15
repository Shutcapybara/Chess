CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -I./Pieces
SRC := $(wildcard *.cpp) $(wildcard Pieces/*.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := chess

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
