//
// Created by Alison Day on 9/19/22.
//

#include "QueriesAutomaton.h"

void QueriesAutomaton::S0(const std::string& input) {
    if (input[index] == 'Q') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S1(const std::string& input) {
    if (input[index] == 'u') {
        index++;
        inputRead++;
        if (input[index] == 'e')
        {
            index++;
            inputRead++;
            if (input[index] == 'r')
            {
                index++;
                inputRead++;
                if (input[index] == 'i')
                {
                    index++;
                    inputRead++;
                    if (input[index] == 'e')
                    {
                        index++;
                        inputRead++;
                        if (input[index] == 's') {
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
        }else {
            Serr();
        }
    }else {
        Serr();
    }
}

