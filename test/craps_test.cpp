#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify die rolls are between 1 and 6")
{
	Die dice;
	dice.roll();
	REQUIRE((dice.rolled_value() <= 6 && dice.rolled_value() >= 1));
	for(int i = 0; i < 10; i++){
		dice.roll();
		REQUIRE((dice.rolled_value() <= 6 && dice.rolled_value() >= 1));
	}
}

TEST_CASE("Verify die rolls in Roll are between 2 and 12")
{
	Die dice1; Die dice2;
	Roll roller(dice1, dice2);
	roller.roll_die();
	REQUIRE((roller.roll_value()<=12 && roller.roll_value()>=2));
	for(int i = 0; i < 10; i++){
		roller.roll_die();
		REQUIRE((roller.roll_value()<=12 && roller.roll_value()>=2));
	}
}