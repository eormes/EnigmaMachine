#ifndef MACHINE_H
#define MACHINE_H
#include <vector>
#include "Rotor.h"
#include "PlugBoard.h"
class Machine : public Exchangeable{
public:
    /**
     * @brief Construct a new Machine object
     * 
     */
    Machine();

    /**
     * @brief encodes a character according to the logic of an enigma machine
     * 
     * @return char 
     */
    char exchange(const char);

    /**
     * @brief adds a rotor to _rotors
     * 
     */
    void addRotor(Rotor);

    /**
     * @brief sets _plugboard
     * 
     */
    void addPlugBoard(PlugBoard);

    /**
     * @brief sets _reflector
     * 
     */
    void addReflector(PlugBoard);

    /**
     * @brief rotates the first rotor, rotates the next rotor every 26 times the one before it rotates
     * 
     */
    void spinRotors();

    /**
     * @brief sets all rotors to their inital notch positions to enable decoding of another message
     * 
     */
    void resetRotors();

private:
    std::vector<Rotor> _rotors;
    PlugBoard _plugboard;
    PlugBoard _reflector;
};
#endif