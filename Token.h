#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    //You'll be creating an automaton file for every one of these tokens, it's why some of them aren't defined yet
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END_OF_FILE
};

class Token
{
private:
    std::string actualValue;
    int lineNumber;
    TokenType typeOfToken;


public:
    Token(TokenType type, std::string description, int line);
    std::string toString();
    std::string getActualValue();
    int getLineNumber();
    TokenType getTypeOfToken();
};

#endif // TOKEN_H

