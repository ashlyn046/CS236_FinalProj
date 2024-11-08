#ifndef PROJECT1_STARTER_CODE_RIGHTPARENTHESESAUTOMATON_H
#define PROJECT1_STARTER_CODE_RIGHTPARENTHESESAUTOMATON_H

#include "Automata/Automaton.h"

class RightParenthesesAutomaton : public Automaton
{
public:
    RightParenthesesAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input) override;
};

#endif //PROJECT1_STARTER_CODE_RIGHTPARENTHESESAUTOMATON_H
