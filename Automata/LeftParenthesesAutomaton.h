#ifndef PROJECT1_STARTER_CODE_LEFTPARENTHESESAUTOMATON_H
#define PROJECT1_STARTER_CODE_LEFTPARENTHESESAUTOMATON_H

#include "Automata/Automaton.h"

class LeftParenthesesAutomaton : public Automaton
{
public:
    LeftParenthesesAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input) override;
};

#endif //PROJECT1_STARTER_CODE_LEFTPARENTHESESAUTOMATON_H
