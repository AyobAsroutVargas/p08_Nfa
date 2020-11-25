/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 8 NFA
 * @author Ayob Asrout Vargas
 * @date 25/11/2020
 * Contact: alu0101350158@ull.edu.es
 * @class Nfa
 * @brief  Non Deterministic Finite automaton built given a file
 * 
 * Given a file wit the specifications of an nfa the class constructs
 * said nfa and provides a method to check if a string is accepted or
 * not by said nfa. The class can also check if all simbols of a string
 * are in the alphabet 
 */
#ifndef Nfa_H_
#define Nfa_H_

#include "state.h"

class Nfa {
 public:
  Nfa(const std::string& fileName, bool& error_loading);

  
  bool evaluate_string(const std::string& input_string) const;
  bool string_is_correct(const std::string& input_string);
 private:
  std::set<char> alphabet_;
  std::set<State> set_of_states_;
  State initial_state_;
  std::set<State> accepted_states_;

  std::set<State> set_conversion(const std::set<int>& set_to_convert) const;
  State get_state(const int& identifier) const;
};

#endif
