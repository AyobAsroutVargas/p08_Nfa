/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 8 NFA
 * @author Ayob Asrout Vargas
 * @date 25/11/2020
 * Contact: alu0101350158@ull.edu.es
 * @class Nfa
 * @brief Non Deterministic Finite automaton built given a file
 * 
 * Given a file with the specifications of an nfa the class constructs
 * said nfa and provides a method to check if a string is accepted or
 * not by said nfa. The class can also check if all simbols of a string
 * are in the alphabet 
 */
#include "nfa.h"
/// @brief constructs the nfa from a file
Nfa::Nfa(const std::string& file_name, bool& error_loading) {
  std::ifstream fin;
  fin.open(file_name);


  int number_of_states, initial_state_identifier;
  char initial_state_line_check;
  fin >> number_of_states;
  fin >> initial_state_identifier;
  fin.get(initial_state_line_check);
  if (initial_state_line_check != '\n') {
    std::cout << "Error loading nfa,"
    << " there must be only one initial state\nProgram exited\n";
    error_loading = true;
    return;
  }

  int current_state_identifier, number_of_transitions;
  bool is_accepted_state;
  char symbol; int next_state_identifier;

  State temporal_state;
  for (int i = 0; i < number_of_states; i++) {
    fin >> current_state_identifier;
    fin >> is_accepted_state;
    fin >> number_of_transitions;

    if (current_state_identifier == initial_state_identifier) {
      initial_state_.set_identifier(current_state_identifier);
    } else temporal_state.set_identifier(current_state_identifier);

    for (int j = 0; j < number_of_transitions; j++) {
      fin >> symbol;
      alphabet_.insert(symbol);

      fin >> next_state_identifier;

      if (current_state_identifier == initial_state_identifier) {
        initial_state_.add_transition(next_state_identifier, symbol);
      } else temporal_state.add_transition(next_state_identifier, symbol);
    }

    if (current_state_identifier == initial_state_identifier) {
      set_of_states_.insert(initial_state_);
    } else set_of_states_.insert(temporal_state);

    if (is_accepted_state) {
      if (current_state_identifier == initial_state_identifier) {
        accepted_states_.insert(initial_state_);
      } else accepted_states_.insert(temporal_state);
    }

    temporal_state.clear();
  }
  if (set_of_states_.size() != (unsigned)number_of_states) {
    std::cout << "Error loading nfa,"
    << " there must be one line describing each state.\n"
    <<"If a state has no transitions it has to be explicitly especified"
    <<"\nProgram exited\n";
    error_loading = true;
    return;
  }
}
/// @return given an int returns a state that has that int as its identifier
State Nfa::get_state(const int& identifier) const {
  State result_state;
  for (const auto& state : set_of_states_) {
    if (state.get_identifier() == identifier) {
      result_state = state;
    }
  }
  return result_state;
}
/// @return given a set of ints returns a set of states wich 
/// identifiers are said ints
std::set<State> Nfa::set_conversion(const std::set<int>& set_to_convert) const {
  std::set<State> converted_set;
  for (const auto& number : set_to_convert) {
    converted_set.insert(get_state(number));
  }
  return converted_set;
}
/// @brief Checks if all symbols of a string are in the alphabet
bool Nfa::string_is_correct(const std::string& input_string) {
  for (unsigned i = 0; i < input_string.size(); i++) {
    if (alphabet_.count(input_string[i]) == 0) {
      return false;
    }
  }
  return true;
}
/// @brief Checks if a string is accepted by the nfa   
bool Nfa::evaluate_string(const std::string& input_string) const {
  std::set<State> result_states, temporal_states, temporal_states_2;
  /// result_states = epsilon_closure(initial_state)
  result_states = set_conversion(initial_state_.epsilon_closure());
  /// result_states = {states which are transitable from any of the states
  /// in result states with the simbol i of the input string}
  for (unsigned i = 0; i < input_string.size(); i++) {
    for (const auto& state : result_states) {
      temporal_states = set_conversion(state.get_next_state_identifiers(input_string[i]));
      for (const auto& state_2 : temporal_states) {
        temporal_states_2.insert(state_2);
      }
    }
    result_states = temporal_states_2;
    temporal_states.clear();
    temporal_states_2.clear();
    /// result_states = result_states U epsilon_closure(result_states)
    for (const auto& state : result_states) {
      temporal_states = set_conversion(state.epsilon_closure());
      for (const auto& state_2 : temporal_states) {
        temporal_states_2.insert(state_2);
      }
    }
    result_states = temporal_states_2;
    temporal_states.clear();
    temporal_states_2.clear();
  }
  /// Check if any of the result states are accepted states
  for (const auto& state : result_states) {
    if (accepted_states_.count(state) == 1) return true;
  }
  return false;
}
