#ifndef EXCHANGEABLE_H
#define EXCHANGEABLE_H
#include <vector>
class Exchangeable{
public:
    Exchangeable() = default;
    virtual ~Exchangeable() = default;
    /**
     * @brief turns one char into another char
     * 
     * @return char 
     */
    virtual char exchange(const char) = 0;
};
#endif