
#include "gtest/gtest.h"
#include "aoc.h"

TEST(DayOne, sectionA)
{
    std::string filename = "../../test/dayOneTestInput.txt";
    int result = getNumberOfIncrementsStatic(filename);
    EXPECT_EQ(result, 6);
}

TEST(DayOne, sectionB)
{
    std::string filename = "../../test/dayOneTestInput2.txt";
    int result = getNumberOfIncrementsSliding(filename);
    EXPECT_EQ(result, 5);
}
