OBJDIR  = obj
OBJS	= $(OBJDIR)/Component.o $(OBJDIR)/Resistor.o $(OBJDIR)/main.o
SOURCE	= src/components/Component.cpp src/components/Resistor.cpp src/main.cpp
HEADER	= include/components/Component.h include/components/Resistor.h
OUT	    = mna
FLAGS	= -g -c -Wall -Iinclude -I/usr/include/eigen3
LFLAGS	= 
CC	    = g++

all:	mna

mna: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

$(OBJDIR)/Component.o: src/components/Component.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Component.o src/components/Component.cpp -std=c++17

$(OBJDIR)/Resistor.o: src/components/Resistor.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Resistor.o src/components/Resistor.cpp -std=c++17

$(OBJDIR)/main.o: src/main.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/main.o src/main.cpp -std=c++17

clean:
	rm -f $(OBJS) $(OUT)

$(shell mkdir -p $(OBJDIR))
