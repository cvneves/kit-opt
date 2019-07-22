
src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

CXXFLAGS = -std=c++11 -I include/ -g

tsp: $(obj)
	$(CXX) -o $@ $^ $(CXXFLAGS)
clean:
	rm -rf *o tsp