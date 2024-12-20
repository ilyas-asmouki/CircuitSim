OBJDIR  = obj
OBJS	= $(OBJDIR)/Component.o $(OBJDIR)/Resistor.o $(OBJDIR)/Capacitor.o $(OBJDIR)/Inductor.o $(OBJDIR)/CurrentSource.o $(OBJDIR)/VoltageSource.o $(OBJDIR)/main.o $(OBJDIR)/Circuit.o
SOURCE	= src/components/Component.cpp src/components/Resistor.cpp src/components/Capacitor.cpp src/components/Inductor.cpp src/components/CurrentSource.cpp src/components/VoltageSource.cpp src/main.cpp src/Circuit.cpp
HEADER	= include/components/Component.h include/components/Resistor.h include/components/Capacitor.h include/components/Inductor.h include/components/CurrentSource.h include/components/VoltageSource.h include/Circuit.h
OUT	    = mna
FLAGS	= -g -c -Wall -Iinclude -I/usr/include/eigen3 -std=c++17 -Wno-class-memaccess
LFLAGS	= 
CC	    = g++

all:	mna

mna: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

$(OBJDIR)/Circuit.o: src/Circuit.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Circuit.o src/Circuit.cpp 

$(OBJDIR)/Component.o: src/components/Component.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Component.o src/components/Component.cpp

$(OBJDIR)/Resistor.o: src/components/Resistor.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Resistor.o src/components/Resistor.cpp

$(OBJDIR)/Capacitor.o: src/components/Capacitor.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Capacitor.o src/components/Capacitor.cpp

$(OBJDIR)/Inductor.o: src/components/Inductor.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/Inductor.o src/components/Inductor.cpp

$(OBJDIR)/CurrentSource.o: src/components/CurrentSource.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/CurrentSource.o src/components/CurrentSource.cpp

$(OBJDIR)/VoltageSource.o: src/components/VoltageSource.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/VoltageSource.o src/components/VoltageSource.cpp

$(OBJDIR)/main.o: src/main.cpp
	$(CC) $(FLAGS) -o $(OBJDIR)/main.o src/main.cpp

clean:
	rm -f $(OBJS) $(OUT)

$(shell mkdir -p $(OBJDIR))
