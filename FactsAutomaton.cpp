//
// Created by Alison Day on 9/19/22.
//

#include "FactsAutomaton.h"

void FactsAutomaton::S0(const std::string& input) {
    if (input[index] == 'F') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S1(const std::string& input) {
    if (input[index] == 'a') {
        index++;
        inputRead++;
        if (input[index] == 'c')
        {
            index++;
            inputRead++;
            if (input[index] == 't')
            {
                index++;
                inputRead++;
                if (input[index] == 's')
                {
                    inputRead++;
                }else {
                    Serr();
                }
            }else {
                Serr();
            }
        }else {
            Serr();
        }
    }else {
        Serr();
    }
}
