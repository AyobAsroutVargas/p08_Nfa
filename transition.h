/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 8 NFA
 * @author Ayob Asrout Vargas
 * @date 25/11/2020
 * Contact: alu0101350158@ull.edu.es
 * @class Transition
 * @brief Contain a symbol and a state which can be transited using said symbol
 */
#ifndef Transition_H_
#define Transition_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Transition {
 public:
  /// getters
  char get_symbol(void) const;
  int get_next_sate_identifier(void) const;

  Transition (void);
  Transition (const int next_state, const char symbol);

  bool operator< (const Transition& transition) const;
  Transition& operator= (const Transition& transition);
 private:
  char symbol_; /// Symbol which the transition consumes
  int next_state_identifier_; /// Next state identifier which the transition goes
};

#endif
