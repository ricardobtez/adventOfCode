
#include <fstream>
#include <iostream>
#include "aoc.h"

int getNumberOfIncrementsSubmarine(const std::string& filename)
{
    int result = 0;
    std::fstream fileHandler;
    fileHandler.open(filename.c_str(), std::ios::in);

    if (fileHandler.is_open())
    {
        int currentDepth = -1;
        std::string line;
        while (std::getline(fileHandler, line))
        {

            int value = std::stoi(line);
            if (-1 == currentDepth) currentDepth = value;

            if (value > currentDepth) ++result;

            // Setting the newly reading from the sonar scanner
            currentDepth = value;
        }
        fileHandler.close();
    }
    else
    {
        std::cout << "There was an error opening the file" << std::endl;
    }
    return result;
}