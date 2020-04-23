M = main
P = FileProcessor
CFLAGS = --std=c++14 

all:$(M)

$(M): $(P).o $(M).o
	g++ $(M).o $(P).o -o $(M)

$(P).o:$(P).hpp $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(M).o:
	g++ $(CFLAGS) -c $(M).cpp -o $(M).o

clean:
	rm -rf *.o $(M)

