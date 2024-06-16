CC := g++
CFLAGS := -std=c++11
DEBUG_FLAGS := -g

TARGET := 3_23

SRCS := 3_23.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

debug : CFLAGS += $(DEBUG_FLAGS)
debug : $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all debug clean