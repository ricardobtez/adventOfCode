
#include <fstream>
#include <iostream>
#include "aoc.h"

int getNumberOfIncrementsStatic(const std::string& filename)
{
    int result = 0;
    std::fstream fileHandler;
    fileHandler.open(filename, std::ios::in);

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

int getNumberOfIncrementsSliding(const std::string& filename, const int windowSize)
{
    int result = 0;
    std::fstream fh;
    fh.open(filename, std::ios::in);

    if (fh.is_open())
    {
        // Create a lambda to calculate the sum of the window
        auto sumWindow = [windowSize](int* array, int offset, int mod) -> int
        {
            int sum = 0;
            int index = offset;
            bool modded = false;
            for (auto i = 0; i < windowSize; i++)
            {
                if (!modded && i > mod)
                {
                    index = 0;
                    modded = true;
                }
                sum += array[index];
                ++index;
            }
            return sum;
        };

        // Creates an array with the size of values to keep track of and its indexes
        int* windowValues = new int[windowSize + 1];
        int index = 0;
        int indexLastWindow = 1;
        bool firstTime = true;
        int lastSum = 0;
        int currentSum = 0;
        std::string line;

        while (std::getline(fh, line))
        {
            int value = std::stoi(line);
            windowValues[index] = value;

            if (firstTime && (index == windowSize))
            {
                firstTime = false;
                lastSum = sumWindow(windowValues, 0, windowSize);
                currentSum = sumWindow(windowValues, 1, windowSize);
                // Only sum if it is larger than previous window
                if (currentSum > lastSum) result++;
                lastSum = currentSum;
                ++indexLastWindow;
            }
            else if (!firstTime)
            {
                currentSum = sumWindow(windowValues, indexLastWindow, windowSize - indexLastWindow);
                // Only sum if it is an increase from previous window
                if (currentSum > lastSum) result++;
                lastSum = currentSum;
                indexLastWindow = (indexLastWindow + 1) % (windowSize + 1);
            }
            index = (index + 1) % (windowSize + 1);
        }
        fh.close();
        delete windowValues;
    }
    else
    {
        std::cout << "There was an error opening the file" << std::endl;
    }
    return result;
}
