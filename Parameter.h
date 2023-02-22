//
// Created by Alison Day on 10/1/22.
//

#ifndef PROJECT1_STARTER_CODE_PARAMETER_H
#define PROJECT1_STARTER_CODE_PARAMETER_H

#include<string>

class Parameter {
private:
    std::string parameterVal;
public:
    explicit Parameter(std::string stringVal);
    ~Parameter() = default;
    const std::string &getParameter() const;
    bool isConstant();
    std::string toString();
};

#endif //PROJECT1_STARTER_CODE_PARAMETER_H
