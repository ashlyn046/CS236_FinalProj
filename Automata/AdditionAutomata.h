#ifndef PROJECT1_STARTER_CODE_ADDITIONAUTOMATA_H
#define PROJECT1_STARTER_CODE_ADDITIONAUTOMATA_H

#include "Automata/Automaton.h"

class AdditionAutomaton : public Automaton
{
public:
    AdditionAutomaton() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_ADDITIONAUTOMATA_H
