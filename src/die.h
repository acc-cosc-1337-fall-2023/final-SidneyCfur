#include <random>

#ifndef DIE_H
#define DIE_H
class Die
{
public:
void roll();
int rolled_value()const{return(roll_value);}
private:
int roll_value = 0;
int sides {6};
};
#endif