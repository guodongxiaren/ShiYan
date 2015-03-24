SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%,$(SRCS))
BIN_DIR = bin
CFLAGS = -O2 

ALL:$(BIN_DIR) $(OBJS) 

%:%.c
	$(CC) -o bin/$@ $^ $(CFLAGS)
$(BIN_DIR):
	mkdir -p $@
clean:
	rm $(OBJS) -rf
.PHONY:clean
