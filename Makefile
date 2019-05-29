OBJS	= pokerHand.o cardClass.o
SOURCE	= pokerHand.cpp cardClass.cpp
HEADER	= cardClass.hpp
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

pokerHand.o: pokerHand.cpp
	$(CC) $(FLAGS) pokerHand.cpp

cardClass.o: cardClass.cpp
	$(CC) $(FLAGS) cardClass.cpp


clean:
	rm -f $(OBJS) $(OUT)
