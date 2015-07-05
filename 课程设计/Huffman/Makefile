BIN = huffman
MAIN = main.cpp
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(filter-out $(MAIN), $(SRCS)) )
CC = g++

$(BIN): $(OBJS) $(MAIN)
	$(CC) $^ -o $@
	
%.o: %.cpp
	$(CC) $^ -c

.PHONY: clean
clean:
	rm  $(OBJS) 
