//
// Created by Alison Day on 9/19/22.
//

#ifndef PROJECT1_STARTER_CODE_IDENTIFIERAUTOMATON_H
#define PROJECT1_STARTER_CODE_IDENTIFIERAUTOMATON_H

#include "Automaton.h"

class IdentifierAutomaton : public Automaton {
private:
    void S1(const std::string& input);
public:
    IdentifierAutomaton() : Automaton(TokenType::ID) {} // Call the base constructor

    void S0(const std::string& input) override;
};

#endif //PROJECT1_STARTER_CODE_IDENTIFIERAUTOMATON_H
