#ifndef PROJECT1_STARTER_CODE_HEADER_H
#define PROJECT1_STARTER_CODE_HEADER_H
#include <string>
#include <vector>

class Header{
private:
    std::vector<std::string> attributes;

public:
    Header() = default;
    ~Header() = default;
    void setAttributes(std::vector<std::string> attributeVal);
    const std::vector<std::string> &getAttributes() const;
    void addAttributes(const std::string& stringVal);

};


#endif //PROJECT1_STARTER_CODE_HEADER_H
