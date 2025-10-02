#ifndef ROTOR_H
#define ROTOR_H

#include "Exchangeable.h"

#include <vector>
class Rotor : public Exchangeable{
public:
    /**
     * @brief Construct a new Rotor object
     * 
     */
    Rotor();

    /**
     * @brief Construct a new Rotor object with a preset and an initial notch posiition
     * 
     */
    Rotor(int,int);

    /**
     * @brief Destroy the Rotor object
     * 
     */
    ~Rotor();

    /**
     * @brief spins a rotor
     * 
     */
    void spin();

    /**
     * @brief exchanges on char according to _wiring
     * 
     * @return char 
     */
    char exchange(char);

    /**
     * @brief inverts the rotor to pass through it backwards
     * 
     */
    void invert();

    /**
     * @brief Get the Notch Position
     * 
     * @return int 
     */
    int getNotchPosition();

    /**
     * @brief resets notch position to origional value
     * 
     */
    void reset();
private:
    std::vector<char> _wiring;
    int _notchPosition;
    bool _inverted;
    const int _INITIALNOTCH;
};
#endif