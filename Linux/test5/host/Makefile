CC = gcc
TARGET = select_host poll_host
OBJ = uart_api.o
ALL: $(OBJ) $(TARGET) 

%: $(OBJ) %.c
	$(CC) $^ -o $@
%.o: %.c
	$(CC) -c $^
.PHONY: clean
clean: 
	rm $(TARGET) $(OBJ) recv.dat
