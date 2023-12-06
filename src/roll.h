#include "die.h"
#include <iostream>

#ifndef ROLL_H
#define ROLL_H
class Roll
{
public:
Roll(Die& dice1, Die& dice2):die1(dice1),die2(dice2){
};
void roll_die();
int roll_value()const{return(value);}
private:
Die& die1;
Die& die2;
bool rolled = false;
int value;
};
#endif