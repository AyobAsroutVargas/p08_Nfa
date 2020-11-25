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
#include "state.h"

State:: State (void):
  transitions_(),
  identifier_(-1) {}

State:: State (int identifier):
  transitions_(),
  identifier_(identifier) {}
/// adds a new transition to the set of transitions
void State::add_transition(int next_state_identifier, char symbol) {
  Transition new_transition(next_state_identifier, symbol);
  transitions_.insert(new_transition);
}
/// @return A set of ints which identifie the states transitable from this 
/// state without consuming any simbol
std::set<int> State::epsilon_closure(void) const {
  std::set<int> result;
  result.insert(identifier_);
  for (const auto& transition : transitions_) { 
    if (transition.get_symbol() == '~') {
      result.insert(transition.get_next_sate_identifier());
    }
  }
  return result;
}
/// @return A set of ints which identifie the states transitable from this 
/// state consuming a certain symbol
std::set<int> State:: get_next_state_identifiers (const char& symbol) const {
  std::set<int> result;
  for (const auto& transition : transitions_) { 
    if (transition.get_symbol() == symbol) {
      result.insert(transition.get_next_sate_identifier());
    }
  }
  return result;
}

void State::set_identifier(const int& identifier) {
  identifier_ = identifier;
}

int State::get_identifier(void) const {
  return identifier_;
}

void State:: clear (void) {
  transitions_.clear();
  identifier_ = -1;
}

bool State:: operator< (const State& state) const {
  if (this->identifier_ < state.identifier_) return true;
  return false;
}

State& State::operator= (const State& state) {
  this->transitions_ = state.transitions_;
  this->identifier_ = state.identifier_;

  return *this;
}
