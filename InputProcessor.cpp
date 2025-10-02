#include "InputProcessor.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

InputProcessor::InputProcessor()
{
}
void InputProcessor::closeStream()
{
    _inputStream.close();
}
bool InputProcessor::openStream()
{
    string inputFile;
    cout << "Enter a file you would like to read the message from:\t";
    cin >> inputFile;
    _inputStream.open(inputFile);
    if(_inputStream.fail())
    {
        cerr << "Error: Could not open file \"" << inputFile << "\"." << endl;
        return false;
    }
    return true;
}
void InputProcessor::read()
{
    char currChar;
    while( _inputStream.get(currChar) )
    {
        _letters.push_back(currChar);
    }

}

std::vector<char> InputProcessor::getLetters()
{
    return _letters;
}