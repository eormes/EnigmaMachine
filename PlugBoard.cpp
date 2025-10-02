#include "PlugBoard.h"
#include <iostream>

PlugBoard::PlugBoard()
{
    
}

PlugBoard::PlugBoard(int preset)
{
    if(preset == 1)
    {
        set('A','Y');
        set('B','R');
        set('C','U');
        set('D','H');
        set('E','Q');
        set('F','S');
        set('G','L');
        set('H','D');
        set('I','P');
        set('J','X');
        set('K','N');
        set('L','G');
        set('M','O');
        set('N','K');
        set('O','M');
        set('P','I');
        set('Q','E');
        set('R','B');
        set('S','F');
        set('T','Z');
        set('U','C');
        set('V','W');
        set('W','V');
        set('X','J');
        set('Y','A');
        set('Z','T');
    }
    if(preset == 2)
    {
        set('A','Y');
        set('B','R');
        set('C','U');
        set('D','H');
        set('E','Q');
        set('F','L');
        set('G','Y');
        set('H','X');
        set('I','V');
        set('J','B');
        set('K','W');
        set('L','F');
        set('M','C');
        set('N','R');
        set('O','Q');
        set('P','U');
        set('Q','O');
        set('R','N');
        set('S','T');
        set('T','S');
        set('U','P');
        set('V','I');
        set('W','K');
        set('X','H');
        set('Y','G');
        set('Z','D');
    }
    if(preset == 3)
    {
        set('A','E');
        set('B','J');
        set('C','M');
        set('D','X');
        set('E','S');
        set('F','L');
        set('G','Y');
        set('H','X');
        set('I','V');
        set('J','B');
        set('K','W');
        set('L','F');
        set('M','C');
        set('N','R');
        set('O','Q');
        set('P','U');
        set('Q','O');
        set('R','N');
        set('S','T');
        set('T','S');
        set('U','P');
        set('V','I');
        set('W','K');
        set('X','H');
        set('Y','G');
        set('Z','D');
    }
    if(preset == -1)
    {
        set('B','I');
        set('G','Q');
        set('J','A');
        set('N','F');
        set('W','T');
        set('T','W');
        set('F','N');
        set('A','J');
        set('Q','G');
        set('I','B');
    }
}

char PlugBoard::exchange(char letterIn)
{
    for(unsigned int i = 0; i < _inputs.size(); i++)
    {
        if (_inputs.at(i) == letterIn)
        {
            return _outputs.at(i);
        }
        else if (_outputs.at(i) == letterIn)
        {
            return _inputs.at(i);
        }
    }
    return letterIn;
}

bool PlugBoard::set(char input,char output)
{
    for(unsigned int i = 0; i < _inputs.size(); i++)
    {
        if(_inputs.at(i) == input || _inputs.at(i) == output || _outputs.at(i) == input || _outputs.at(i) == output)
        {
            return false;
        }
    }
    _inputs.push_back(input);
    _outputs.push_back(output);
    return true;
}