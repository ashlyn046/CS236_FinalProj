#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automata/Automaton.h"
#include "Token/Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();


public:
    Lexer();
    ~Lexer();
    void Run(std::string& input);
    std::string lexerToString();
    std::vector<Token*> getTokens();

};

#endif // LEXER_H

