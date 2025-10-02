#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "Exchangeable.h"

#include <vector>
class PlugBoard : public Exchangeable{
public:
    /**
     * @brief Construct a new Plug Board object
     * 
     */
    PlugBoard();

    /**
     * @brief Construct a new Plug Board object with a preset
     * 
     */
    PlugBoard(int);

    /**
     * @brief swaps a letter according to _inputs and _outputs
     * 
     * @return char 
     */
    char exchange(const char);

    /**
     * @brief sets up a connection between _inputs and _outputs
     * 
     * @return true 
     * @return false 
     */
    bool set(char,char);
private:
    std::vector<char> _inputs;
    std::vector<char> _outputs;
};
#endif