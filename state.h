/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 8 NFA
 * @author Ayob Asrout Vargas
 * @date 25/11/2020
 * Contact: alu0101350158@ull.edu.es
 * @class State
 * @brief Contains a set of transitions and an identifier
 * 
 * The class provides methods to identifie the next states to which
 * the state can transit consuming a symbol, or not, in the case of
 * the epsilon_closure
 */
#ifndef State_H_
#define State_H_

#include <set>
#include "transition.h"

class State {
 public:
  State(void);
  State(int identifier);

  void add_transition(int next_state_identifier, char symbol);
  std::set<int> get_next_state_identifiers (const char& symbol) const;
  std::set<int> epsilon_closure(void) const;

  void set_identifier(const int& identifier);
  int get_identifier(void) const;

  void clear(void);
  bool operator< (const State& state) const;
  State& operator= (const State& state);
 private:
  std::set<Transition> transitions_;
  int identifier_;
};

#endif
