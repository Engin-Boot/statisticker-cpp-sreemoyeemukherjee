#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>
#include <math.h>

TEST_CASE("when all inputs are real numbers of type float then report average, minimum and maximum to an accuracy of 0.001") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001f;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average, min, max is NaN for empty array") {
    auto computedStats = Statistics::ComputeStatistics({});
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    REQUIRE(isnan(computedStats.average)==true);
    REQUIRE(isnan(computedStats.max)==true);
    REQUIRE(isnan(computedStats.min)==true);
    //Use http://www.cplusplus.com/reference/cmath/isnan/
}
TEST_CASE("when some elements in the input are NaN then calculate stats of remaining numbers") {
    auto computedStats = Statistics::ComputeStatistics({NAN,1.5,NAN,3.0,4.5,NAN});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 3.000) < epsilon);
    REQUIRE(std::abs(computedStats.max - 4.5) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}