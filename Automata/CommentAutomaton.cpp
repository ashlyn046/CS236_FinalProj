#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input){
    if (input[index] == '|'){
        inputRead++;
        index++;
        S2(input);
    }
    else {
        S4(input);
    }
}


void CommentAutomaton::S2(const std::string& input) {
    if(!(input.substr(index,input.length()).empty())){
        if (input[index] == '\n'){
            newLines ++;
        }

        if (input[index] != '|') {
            inputRead++;
            index++;
            S2(input);
        }
        else{
            inputRead++;
            index++;
            S3(input);
        }
    }
    else{
        type = TokenType::UNDEFINED;
    }
}


void CommentAutomaton::S3(const std::string& input) {
    if(!(input.substr(index,input.length()).empty())){
        if (input[index] != '#') {
            if(input[index] == '\n'){
                newLines++;
            }
            inputRead++;
            index++;
            S2(input);
        }
        else if (input[index] == '#') {
            inputRead++;
            index++;
        }
    }
    else{
        type = TokenType::UNDEFINED;
    }
}

void CommentAutomaton::S4(const std::string& input) {
    if((input.substr(index,input.length()).empty())){
        return;
    }
    if(!(input.substr(index,input.length()).empty())){
        if(input[index] == '\n'){
            return;
        }
        else{
            inputRead++;
            index++;
            S4(input);
        }
    }
}

