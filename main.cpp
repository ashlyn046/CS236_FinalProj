#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "interpreter/Interpreter.h"
#include <fstream>

int main(__attribute__((unused)) int argc, char *argv[]) //Put this back to how it used to be? Using suggested Clion edits
{
    std::string fileName = argv[1];
    std::ifstream filestream;
    filestream.open(fileName);std::stringstream ss;
    ss << filestream.rdbuf();
    std::string inputString = ss.str();

    auto* lexer = new Lexer();
    lexer->Run(inputString);
    std::vector<Token*> tokenVectorCopy = lexer->getTokens();

    auto *parser = new Parser(tokenVectorCopy);
    parser->parse();

    auto *interpreter = new Interpreter(parser->getDlp());
    interpreter->run();

    delete lexer;
    return 0;
}