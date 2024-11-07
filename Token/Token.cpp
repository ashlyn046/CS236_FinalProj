#include "Token/Token.h"

#include <utility>

Token::Token(TokenType type, std::string description, int line)
{
    this->typeOfToken = type;
    this->actualValue = std::move(description);
    this->lineNumber = line;
}

std::string Token::toString()
{
    std::string tokenTypeAsString;
    switch (typeOfToken) {
        case TokenType::COMMA:
            tokenTypeAsString = "COMMA";
            break;
        case TokenType::PERIOD:
            tokenTypeAsString = "PERIOD";
            break;
        case TokenType::Q_MARK:
            tokenTypeAsString = "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            tokenTypeAsString = "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            tokenTypeAsString = "RIGHT_PAREN";
            break;
        case TokenType::COLON:
            tokenTypeAsString = "COLON";
            break;
        case TokenType::COLON_DASH:
            tokenTypeAsString = "COLON_DASH";
            break;
       case TokenType::MULTIPLY:
            tokenTypeAsString = "MULTIPLY";
            break;
        case TokenType::ADD:
            tokenTypeAsString = "ADD";
            break;
        case TokenType::SCHEMES:
            tokenTypeAsString = "SCHEMES";
            break;
        case TokenType::FACTS:
            tokenTypeAsString = "FACTS";
            break;
        case TokenType::RULES:
            tokenTypeAsString = "RULES";
            break;
        case TokenType::QUERIES:
            tokenTypeAsString = "QUERIES";
            break;
        case TokenType::ID:
            tokenTypeAsString = "ID";
            break;
        case TokenType::STRING:
            tokenTypeAsString = "STRING";
            break;
        case TokenType::COMMENT:
            tokenTypeAsString = "COMMENT";
            break;
        case TokenType::UNDEFINED:
            tokenTypeAsString = "UNDEFINED";
            break;
        case TokenType::END_OF_FILE:
            tokenTypeAsString = "EOF";
            break;
        default:
            break;
    }
    std::string output = "(" + tokenTypeAsString + ",\"" + this->actualValue + "\"," + std::to_string(this->lineNumber) + ")";

    return(output);
}

std::string Token::getActualValue()
{
    return actualValue;
}
int Token::getLineNumber()
{
    return lineNumber;
}

TokenType Token::getTypeOfToken()
{
    return typeOfToken;
}
