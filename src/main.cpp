#include <iostream>
#include "aoc.h"

#define INPUTS_START_FOLDER     std::string("../../Inputs/")
void dayOne();

int main()
{
    std::cout << "Welcome to Advent Of Code 2021" << std::endl;
    dayOne();
    return 0;
}

void dayOne()
{
    std::string inputFilename = INPUTS_START_FOLDER + "DayOneInput.txt";
    int increments = getNumberOfIncrementsStatic(inputFilename);
    std::cout << "The number of increments in the static window is:" <<
        std::to_string(increments) << std::endl;
    increments = getNumberOfIncrementsSliding(inputFilename, 3);
    std::cout << "The number of increments in the sliding window is:" <<
        std::to_string(increments) << std::endl;
}
