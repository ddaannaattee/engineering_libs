# change application name here (executable output name)
TARGET=Coolculator

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS= -lm $(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=	main.o ../dl_lib/engineering.o formfunctions.o cylinderforce.o torqueconversion.o hmotorinertia.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o: main.c infostruct.h ../dl_lib/engineering.h formfunctions.h cylinderforce.h torqueconversion.h hmotorinertia.h
	$(CC) -c $(CCFLAGS) main.c $(GTKLIB) -o main.o

/home/artichoke/Documents/libs/engineering.o: ../dl_lib/engineering.c ../dl_lib/engineering.h
	$(CC) -c $(CCFLAGS) "../dl_lib/engineering.c" $(GTKLIB) -o "../dl_lib/engineering.o"

formfunctions.o: formfunctions.c formfunctions.h
	$(CC) -c $(CCFLAGS) formfunctions.c $(GTKLIB) -o formfunctions.o

cylinderforce.o: cylinderforce.c cylinderforce.h
	$(CC) -c $(CCFLAGS) cylinderforce.c $(GTKLIB) -o cylinderforce.o

torqueconversion.o: torqueconversion.c torqueconversion.h
	$(CC) -c $(CCFLAGS) torqueconversion.c $(GTKLIB) -o torqueconversion.o

hmotorinertia.o: hmotorinertia.c hmotorinertia.h
	$(CC) -c $(CCFLAGS) hmotorinertia.c $(GTKLIB) -o hmotorinertia.o

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
