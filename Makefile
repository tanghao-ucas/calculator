TARGET := main
CC := gcc
STANDARD := -std=c99
CFLAG := -Wall
INCLUDES := -I. -Ilib/calculator/ -Ilib/stack/

SRC = $(wildcard *.c ./lib/calculator/*.c ./lib/stack/*.c)
DEPENDENCY = $(wildcard *.h ./lib/calculator/*.h ./lib/stack/*.h)
OBJECTS = $(patsubst %.c,%.o,$(SRC));

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(INCLUDES) $(STANDARD)

%.o: %.c $(DEPENDENCY)
	$(CC) -c $(INCLUDES) $(CFLAG) $(CPPFLAG) $(STANDARD) $< -o $@ 

.PHONY: clean
clean:     
	rm  -rf $(TARGET) $(OBJECTS)