OPTS = -g -c -Wall -Werror
all: RateAnalysis clean
RateAnalysis: RateAnalysis.o
	g++ -o RateAnalysis RateAnalysis.o

RateAnalysis.o: RateAnalysis.cc
	g++ $(OPTS) RateAnalysis.cc
clean:
	rm -f *.o
	rm -f *~
	