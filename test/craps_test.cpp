#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE("Verify Shooter returns a roll")
{
	Die dice1; Die dice2;
	Shooter shoot;
	for(int i = 0; i < 10; i++){
		REQUIRE((shoot.throw_die(dice1, dice2)->roll_value()<=12 &&shoot.throw_die(dice1, dice2)->roll_value()>=2));
	}
}

TEST_CASE("Verify ComeOutPhase returns values")
{
	Die dice1; Die dice2;
	Shooter shoot;
	ComeOutPhase phase1;
	vector<bool> check{false,false,false};
	for(int i = 0; i < 10; i++){
		if(phase1.get_outcome(shoot.throw_die(dice1,dice2)) == Phase::RollOutcome::natural)
		{
			check[0] = true;
		}
		else if(phase1.get_outcome(shoot.throw_die(dice1,dice2)) == Phase::RollOutcome::craps)
		{
			check[1] = true;
		}
		else if(phase1.get_outcome(shoot.throw_die(dice1,dice2)) == Phase::RollOutcome::point)
		{
			check[2] = true;
		}
	}
	REQUIRE((check[0] == true && check[1] == true && check[2] == true));
}

TEST_CASE("Verify PointPhase returns values")
{
	Die dice1; Die dice2;
	Shooter shoot;
	PointPhase phase1(6);
	vector<bool> check{false,false,false};
	for(int i = 0; i < 10; i++){
		if(phase1.get_outcome(shoot.throw_die(dice1,dice2)) == Phase::RollOutcome::point)
		{
			check[0] = true;
		}
		else if(phase1.get_outcome(shoot.throw_die(dice1,dice2)) == Phase::RollOutcome::seven_out)
		{
			check[1] = true;
		}
		else if(phase1.get_outcome(shoot.throw_die(dice1,dice2)) == Phase::RollOutcome::nopoint)
		{
			check[2] = true;
		}
	}
	REQUIRE((check[0] == true && check[1] == true && check[2] == true));
}