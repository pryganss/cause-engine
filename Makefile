CXX     := g++
LDLIBS  := -lSDL3

all: *.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o main.out

%.o : %.cc
	$(CXX) -c $^ -o $@

clean:
	rm *.o
