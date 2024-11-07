//
// Created by Alison Day on 9/19/22.
//

#include "RightParenthesesAutomaton.h"

void RightParenthesesAutomaton::S0(const std::string& input) {
    if (input[index] == ')') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}