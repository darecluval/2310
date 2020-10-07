# Define the compiling extension and flags used during compiling
# Also define the target executable created
CC=gcc
CFLAGS=-Wall -g 
LFLAGS=-lm 
TARGET=lab9 
 
# Locate all c source, header, and object files. The wildcard means 
# it will find all files ending in the specified extension (ie. .c or .h)
C_SRCS := \
	$(wildcard *.c) \
	$(wildcard src/*.c) \
	$(wildcard src/**/*.c) 
HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h)
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# When the compiling is finished, send the message to the terminal
all: build
		@echo "All Done!"

# Compile the files gcc and flags from the given objects into the 
# specified target executable file
build: $(OBJS)
		$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)
 
# Locate all src files in the root directory
bin/%.o: %.c $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

# Locate all files in the nested src directory
bin/%.o: src/%.c $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@


# When "make clean" is run, the executable targets created from
# the "make run"
clean:
		rm -f $(TARGET)
		rm -rf bin

# "make run" will run the executable target made during the 
# compiling "make"
run: build
		./$(TARGET)

# Locate all .c, .h, & executable targets
which:
		@echo "FOUND SOURCES: ${C_SRCS}"
		@echo "FOUND HEADERS: ${HDRS}"
		@echo "TARGET OBJS: ${OBJS}"

