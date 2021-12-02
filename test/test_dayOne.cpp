
#include "gtest/gtest.h"
#include "aoc.h"

TEST(DayOne, dummytest)
{
    std::string filename = "../../test/dayOneTestInput.txt";
    int result = getNumberOfIncrementsSubmarine(filename);
    EXPECT_EQ(result, 6);
}
