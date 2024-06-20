CXX = g++
FLAGS = -Wall -Wextra -std=c++20

TARGET = main
TEST_TARGET = tests

SRCS = main.cpp
TEST_SRCS = example_tests.cpp

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SRCS) bitboard_utils.h
	$(CXX) $(FLAGS) -o $(TARGET) $(SRCS)

$(TEST_TARGET): $(TEST_SRCS) test_framework.h
	$(CXX) $(FLAGS) -o $(TEST_TARGET) $(TEST_SRCS)

# Rule for cleaning up build files
clean: 
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all clean 