CXX=g++
CXXFLAGS=-std=c++20 -Wall -lgsl

.PHONY: graph
.PRECIOUS: %.x

all: leapfrog.x

leapfrog.x: code/leapfrog.cpp code/leapfrog.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

graph: leapfrog.x results/hay.dat results/no_hay.dat
	code/graph.py

clean:
	@find . -type f -name "*.dat" -delete
	@find . -type f -name "*.x" -delete
clean_results:
	@find . -type f -name "*.pdf" -delete
	@find . -type f -name "*.png" -delete
