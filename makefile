## Email: maayan1sher@gmail.com


CXX=g++
CXXFLAGS=-std=c++17 -Wall 
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = tree
SRCS = main.cpp 
HEADERS = tree.hpp complex.hpp node.hpp
OBJS = $(SRCS:.cpp=.o)
TEST_SRCS = test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp = .o)
INCLUDES = -I.

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_FLAGS)


%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< $(INCLUDES)


test: $(TEST_OBJS) $(OBJ)
		$(CXX) $(CXXFLAGS) $^ -o test
		./test


clean:
	rm -f *.o main test tree

.PHONY: all clean test

