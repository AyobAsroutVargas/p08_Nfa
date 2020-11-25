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
#include "transition.h"

/// Constructor por defecto
Transition::Transition(void):
symbol_{},
next_state_identifier_{} {}

/// Constructor
Transition::Transition(const int next_state, const char symbol):
symbol_{symbol},
next_state_identifier_{next_state} {}

char Transition::get_symbol(void) const {
  return symbol_;
}

int Transition::get_next_sate_identifier(void) const {
  return next_state_identifier_;
}
/// Sobrecarga del operador '<'
bool Transition::operator< (const Transition& transition) const {
  if ((this->symbol_ <= transition.symbol_)) return true;
  return false;
}
/// Sobrecarga del operador '='
Transition& Transition::operator= (const Transition& transition) {
  this->symbol_ = transition.symbol_;
  this->next_state_identifier_ = transition.next_state_identifier_;
  return *this;
}
