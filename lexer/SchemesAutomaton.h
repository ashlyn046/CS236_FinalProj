#ifndef PROJECT1_STARTER_CODE_SCHEMESAUTOMATON_H
#define PROJECT1_STARTER_CODE_SCHEMESAUTOMATON_H

#include "Automaton.h"

class SchemesAutomaton : public Automaton{
private:
    void S1(const std::string &input);

public:
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor

    void S0(const std::string &input) override;
};

#endif //PROJECT1_STARTER_CODE_SCHEMESAUTOMATON_H
