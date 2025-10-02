#include "Rotor.h"
#include <iostream>
Rotor::Rotor()
    : _notchPosition(0), _inverted(false), _INITIALNOTCH(0)
{
    // Initialize with identity wiring (A to A, B to B, ...)
    for (int i = 0; i < 26; ++i) {
        _wiring.push_back((char)(i + 65));  // A to Z
    }
}

Rotor::Rotor(int preset, int notchPos)
    : _inverted(false), _INITIALNOTCH(notchPos)
{
    // Initialize with preset wiring
    if (preset == 1) {
        _wiring = {'D','M','T','W','S','I','L','R','U','Y','Q','N','K','F','E','J','C','A','Z','B','P','G','X','O','H','V'};
    }
    else if (preset == 2) {
        _wiring = {'H','Q','Z','G','P','J','T','M','O','B','L','N','C','I','F','D','Y','A','W','V','E','U','S','R','K','X'};
    }
    else if (preset == 3) {
        _wiring = {'U','Q','N','T','L','S','Z','F','M','R','E','H','D','P','X','K','I','B','V','Y','G','J','C','W','O','A'};
    }
    else if (preset == 4)
    {
        _wiring = {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'};
    }
    else if (preset == 5)
    {
        _wiring = {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'};
    }
    else if (preset == 6)
    {
        _wiring = {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'};
    }
    _notchPosition = notchPos % 26;
}

Rotor::~Rotor()
{
}

void Rotor::spin()
{
    _notchPosition = (_notchPosition + 1) % 26;
}

void Rotor::invert()
{
    _inverted = !_inverted;
}
char Rotor::exchange(const char INPUT) {
    char letterOut = '0';

    // Calculate the index of the letter in the alphabet (0-25)
    int index = INPUT - 'A';

    if (!_inverted) {
        // Apply rotor position shift (circular) for the forward pass
        index = (index + _notchPosition) % 26;

        // The output character is mapped directly via the wiring
        letterOut = _wiring[index];
    } else {
        // For reverse pass, find the corresponding character in the wiring
        for (int i = 0; i < 26; i++) {
            if (_wiring[i] == INPUT) {
                // Calculate the index based on the current rotor's position
                if(i - _notchPosition < 0)
                {
                    letterOut = i - _notchPosition + 26 + 'A';
                }
                else
                {
                    letterOut = ((i - _notchPosition) % 26) + 'A';
                }
                break;
            }
        }
    }

    // Return the mapped character
    return letterOut;
}

int Rotor::getNotchPosition()
{
    return _notchPosition;
}

void Rotor::reset()
{
    _notchPosition = _INITIALNOTCH % 26;
}