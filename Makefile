CXX     := g++
LDLIBS  := -lSDL3	

main: main.o game_renderer.o atlas.o map.o grid.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o main.out

%.o : %.cc
	$(CXX) -c $^ -o $@

clean:
	rm *.o
