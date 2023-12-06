#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify die rolls are between 1 and 6")
{
	die Dice;
	Dice.roll();
	REQUIRE((Dice.rolled_value() <= 6 && Dice.rolled_value() >= 1));
}