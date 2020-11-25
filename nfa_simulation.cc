/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 8 NFA
 * @author Ayob Asrout Vargas
 * @date 25/11/2020
 * Contact: alu0101350158@ull.edu.es
 * Compilation: g++ -std=c++14 -g -Wall -o nfa_simulation transition.cc state.cc nfa.cc nfa_simulation.
 * Usage: ./nfa_simulation input.nfa input.txt output.txt
 * 
 * The program constructs a nfa from the 'input.nfa' file , and checks
 * if all the strings in 'input.txt' are accepted by said nfa or not.
 * The result will go into output.txt
 */
#include "nfa.h"

int main(int argc, char* argv[]) {
  if ((argc == 2)) {
    std::string argument1 = argv[1];
    if (argument1 == "--help") {
      std::cout << "Usage: " << argv[0] << " input.nfa input.txt" 
      << " output.txt" << "\n\n The program constructs a nfa from the"
      << " 'input.nfa' file, and checks if all the strings in 'input.txt'\n"
      << "are accepted by said nfa or not. The result will go into "
      << "output.txt \n";
      return 0;
    }
  } else if(argc != 4) {
    std::cout << "Usage: " << argv[0] << " input.nfa input.txt" 
    << " output.txt\nTry '" << argv[0] << "' --help for more information\n";
    return 0;
  }
  std::string nfa_file_name = argv[1];
  std::string input_file_name = argv[2];
  std::string output_file_name = argv[3];
  std::string input_string;
  std::ifstream fin;
  std::ofstream fout;

  fin.open(input_file_name);
  fout.open(output_file_name);
  bool error_loading{false};
  Nfa nfa(nfa_file_name, error_loading);
  if(error_loading) {
    return 0;
  } else {
      while(std::getline(fin, input_string)) {
      fout << input_string << " -> ";
      if (!nfa.string_is_correct(input_string)) {
        fout << "Error. Not all symbols present in alphabet\n";
      } else if(nfa.evaluate_string(input_string)) {
        fout << "Yes\n";
      } else {
        fout << "No\n";
      }
    }
  }
}
