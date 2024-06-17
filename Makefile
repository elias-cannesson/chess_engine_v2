CXX = g++
FLAGS = -Wall -Wextra 

TARGET = main
SRCS   = main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(FLAGS) -o $(TARGET) $(SRCS)

# Rule for cleaning up build files
clean: 
	rm -f $(TARGET)

.PHONY: all clean 