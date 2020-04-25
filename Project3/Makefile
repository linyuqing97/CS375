M = main
P = FileProcessor
I = inputgenerator
O = generator
CFLAGS = --std=c++14 

all:$(M) $(I) $(O)

$(M): $(P).o $(M).o
	g++ $(M).o $(P).o -o $(M)

$(P).o:$(P).hpp $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(M).o:
	g++ $(CFLAGS) -c $(M).cpp -o $(M).o
	
$(I).o:
	g++ $(CFLAGS) -c $(I).cpp -o $(I).o

$(I): $(I).o
	g++ $(I).o -o $(I)

$(O).o:
	g++ $(CFLAGS) -c $(O).cpp -o $(O).o

$(O): $(P).o $(O).o
	g++ $(O).o $(P).o -o $(O)
	
clean:
	rm -rf *.o $(M) $(I) $(O)

