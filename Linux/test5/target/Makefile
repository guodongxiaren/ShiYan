CC = gcc
TARGET = select_target poll_target
OBJ = uart_api.o
ALL: $(OBJ) $(TARGET) 

%: $(OBJ) %.c
	$(CC) $^ -o $@
%.o: %.c
	$(CC) -c $^
.PHONY: clean
clean: 
	rm $(TARGET) $(OBJ) recv.dat
