OBJS	= pokerHand.o handClass.o cardClass.o
SOURCE	= pokerHand.cpp handClass.cpp cardClass.cpp
HEADER	= handClass.hpp cardClass.hpp
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

pokerHand.o: pokerHand.cpp
	$(CC) $(FLAGS) pokerHand.cpp

handClass.o: handClass.cpp
	$(CC) $(FLAGS) handClass.cpp

cardClass.o: cardClass.cpp
	$(CC) $(FLAGS) cardClass.cpp


clean:
	rm -f $(OBJS) $(OUT)
