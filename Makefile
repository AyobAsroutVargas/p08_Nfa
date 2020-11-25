CXX = g++
CXXFLAGS = -std=c++14 -g -Wall

nfa_simulation: transition.o state.o nfa.o nfa_simulation.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

transition.o: transition.cc transition.h
	$(CXX) -c transition.cc

state.o: state.cc transition.h state.h
	$(CXX) -c state.cc

nfa.o: nfa.cc transition.h state.h nfa.h
	$(CXX) -c nfa.cc

nfa_simulation.o: nfa_simulation.cc transition.h state.h nfa.h
	$(CXX) -c nfa_simulation.cc

clean:
	rm nfa_simulation *.o output.txt
