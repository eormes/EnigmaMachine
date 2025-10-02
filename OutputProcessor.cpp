#include "OutputProcessor.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

OutputProcessor::OutputProcessor()
{
}

void OutputProcessor::closeStream()
{
    _outputStream.close();
}

/**
 * @brief opens output stream
 * 
 * @return true 
 * @return false 
 */
bool OutputProcessor::openStream()
{
    string inputFile;
    cout << "Enter a file you would like to read the message to:\t";
    cin >> inputFile;
    _outputStream.open(inputFile);
    if(_outputStream.fail())
    {
        cerr << "Error: Could not open file \"" << inputFile << "\"." << endl;
        return false;
    }
    return true;
}

void OutputProcessor::writeFrom(const std::vector<char> LETTERS)
{
    for(unsigned int i = 0; i < LETTERS.size(); i++)
    {
        _outputStream << LETTERS.at(i);
    }
}
