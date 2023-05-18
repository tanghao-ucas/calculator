TARGET := main
CC := gcc
STANDARD := -std=c99
CFLAG := -Wall
INCLUDES := -I. -Ilib/ -Ilib/calculator/ -Ilib/vector/ -Ilib/stack/ 

SOURCE = $(wildcard *.c ./lib/calculator/*.c ./lib/vector/*.c ./lib/stack/*.c)
DEPENDENCY = $(wildcard *.h ./lib/*.h ./lib/calculator/*.h ./lib/vector/*.h ./lib/stack/*.h )
OBJECTS = $(patsubst %.c,%.o,$(SOURCE));

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(INCLUDES) $(STANDARD)

%.o: %.c $(DEPENDENCY)
	$(CC) -c $(INCLUDES) $(CFLAG) $(CPPFLAG) $(STANDARD) $< -o $@ 

.PHONY: clean
clean:     
	rm  -rf $(TARGET) $(OBJECTS)