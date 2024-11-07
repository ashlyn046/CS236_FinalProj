//
// Created by Alison Day on 11/2/22.
//

#ifndef PROJECT1_STARTER_CODE_TUPLE_H
#define PROJECT1_STARTER_CODE_TUPLE_H
#include <string>
#include <vector>

class Tuple {
// Tuple - contains vector of values (string)
private:
    std::vector<std::string> values;

public:
    Tuple() = default;
    ~Tuple() = default;
    Tuple(std::vector<std::string> vectorOfStrings);
    bool operator<(const Tuple &rhs) const;
    const std::vector<std::string> &getValues() const;
    void addValue(const std::string& stringVal);

    // Watch for pointers

};


#endif //PROJECT1_STARTER_CODE_TUPLE_H
