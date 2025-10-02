#ifndef OUTPUTPROCESSOR_H
#define OUTPUTPROCESSOR_H
#include <fstream>
#include <vector>

class OutputProcessor
{
public:
    /**
     * @brief Construct a new Output Processor object
     * 
     */
    OutputProcessor();

    /**
     * @brief closes output stream
     * 
     */
    void closeStream();

    /**
     * @brief asks the user to specify which file to write to
     * 
     * @return true 
     * @return false 
     */
    bool openStream();

    /**
     * @brief writes a vector of characters to a file
     * 
     */
    void writeFrom(const std::vector<char>);

private:
    std::ofstream _outputStream;
};

#endif