#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H
#include <fstream>
#include <vector>

class InputProcessor
{
public:
    /**
     * @brief Construct a new Input Processor object
     * 
     */
    InputProcessor();

    /**
     * @brief Closes the input stream
     * 
     */
    void closeStream();

    /**
     * @brief opens the input stream and asks the user to specify what file they would like to open
     * 
     * @return true 
     * @return false 
     */
    bool openStream();

    /**
     * @brief reads a file and adds the letters to _letters
     * 
     */
    void read();

    /**
     * @brief Get the _letters vector of chars
     * 
     * @return std::vector<char> 
     */
    std::vector<char> getLetters();

private:
    std::ifstream _inputStream;
    std::vector<char> _letters;
};

#endif