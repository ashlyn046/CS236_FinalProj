//
// Created by Alison Day on 9/19/22.
//

#include "LeftParenthesesAutomaton.h"

void LeftParenthesesAutomaton::S0(const std::string& input) {
    if (input[index] == '(') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}