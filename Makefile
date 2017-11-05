# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -std=c++11 -Wall

# the build target executable:
TARGET = main
TARGET2 = test

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp ./class/Utils.cpp ./class/Usuarios.cpp ./class/Distributios.cpp ./class/Zonas.cpp

dist: $(TARGET2)

$(TARGET2): $(TARGET2).cpp
	$(CC) $(CFLAGS) -o $(TARGET2) $(TARGET2).cpp ./class/Utils.cpp
clean:
	$(RM) $(TARGET)
	$(RM) $(TARGET2)