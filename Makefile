OBJDIR  = obj
OBJS	= $(OBJDIR)/Component.o $(OBJDIR)/Resistor.o $(OBJDIR)/CurrentSource.o $(OBJDIR)/main.o $(OBJDIR)/Circuit.o
SOURCE	= src/components/Component.cpp src/components/Resistor.cpp src/components/CurrentSource.cpp src/main.cpp src/Circuit.cpp
HEADER	= include/components/Component.h include/components/Resistor.h include/components/CurrentSource.h include/Circuit.h
OUT	    = mna
FLAGS	= -g -c -Wall -Iinclude -I/usr/include/eigen3
LFLAGS	= 
CC	    = g++

all:	mna

mna: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

$(OBJDIR)/Circuit.o: src/Circuit.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Circuit.o src/Circuit.cpp -std=c++17

$(OBJDIR)/Component.o: src/components/Component.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Component.o src/components/Component.cpp -std=c++17

$(OBJDIR)/Resistor.o: src/components/Resistor.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Resistor.o src/components/Resistor.cpp -std=c++17

$(OBJDIR)/CurrentSource.o: src/components/CurrentSource.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/CurrentSource.o src/components/CurrentSource.cpp -std=c++17

$(OBJDIR)/main.o: src/main.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/main.o src/main.cpp -std=c++17

clean:
	rm -f $(OBJS) $(OUT)

$(shell mkdir -p $(OBJDIR))
