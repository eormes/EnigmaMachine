#include "Machine.h"
#include <iostream>
using namespace std;
Machine::Machine()
{
}

char Machine::exchange(const char LETTERIN)
{
    char letterOut = LETTERIN;

    //set lowercase letters to uppercase
    if(letterOut >= 'a' && letterOut <= 'z')
    {
        letterOut = letterOut + 'A' - 'a';
    }

    //if it is a letter
    if(letterOut > 64 && letterOut < 91)
    {
        //send it through the plugboard
        letterOut = _plugboard.exchange(letterOut);
        //send it through each rotor
        for(unsigned int i = 0; i < _rotors.size(); i++)
        {
            letterOut = _rotors.at(i).exchange(letterOut);
            _rotors.at(i).invert();
        }
        //send it through the reflector
        letterOut = _reflector.exchange(letterOut);
        //send it back through each rotor
        for(int i = _rotors.size()-1 ; i >= 0; i--)
        {
            letterOut = _rotors.at(i).exchange(letterOut);
            _rotors.at(i).invert();
        }
        //send it through the plugboard again
        letterOut = _plugboard.exchange(letterOut);
        //spin rotors
        spinRotors();
    }
    return letterOut;
}

void Machine::spinRotors()
{
    if(_rotors.size() > 0)
    {
        //spin the first rotor every time
        _rotors.at(0).spin();
        for(unsigned int i = 0; i < _rotors.size() - 1; i++)
        {
            //spin each rotor once every 26 times the rotor before it rotates
            if(_rotors.at(i).getNotchPosition() == 0)
            {
                _rotors.at(i + 1).spin();
            }
        }
    }
}

void Machine::addRotor(Rotor rotorIn)
{
    _rotors.push_back(rotorIn);
}

void Machine::addPlugBoard(PlugBoard boardIn)
{
    _plugboard = boardIn;
}

void Machine::addReflector(PlugBoard reflectorIn)
{
    _reflector = reflectorIn;
}

void Machine::resetRotors()
{
    for(unsigned int i = 0; i < _rotors.size(); i++)
    {
        _rotors.at(i).reset();
    }
}