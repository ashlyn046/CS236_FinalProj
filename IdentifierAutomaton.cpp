//
// Created by Alison Day on 9/19/22.
//

#include "IdentifierAutomaton.h"
#include <cctype>

void IdentifierAutomaton::S0(const std::string& input) {
    if (isalpha(input.at(index))) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdentifierAutomaton::S1(const std::string& input) {
    if ((int)input.size() > index) {
        if (isalnum(input.at(index))) {
            inputRead++;
            index++;
            S1(input);
        }
    }
}
