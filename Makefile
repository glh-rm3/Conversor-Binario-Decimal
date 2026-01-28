TARGET=conversor
DEBUG=-g
OPT=-O2
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS= main.o project.cpp
all: $(OBJS)
		$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: main.cpp
		$(CC) -c $(CCFLAGS) main.cpp -o main.o

project.o: project.cpp
		$(CC) -c $(CCFLAGS) project.cpp -o project.o

install:
		@install $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
		@rm /usr/local/bin/$(TARGET)

clean:
		rm -f *.o
