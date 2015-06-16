CC = gcc
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%,$(SRCS))
TMP = *.txt
BIN_DIR = bin
CFLAGS = -O2 -g

ALL:$(BIN_DIR) $(OBJS) 

%:%.c
	$(CC) -o bin/$@ $^ $(CFLAGS)
$(BIN_DIR):
	mkdir -p $@
clean:
	rm $(OBJS) $(TMP) -rf
.PHONY:clean
