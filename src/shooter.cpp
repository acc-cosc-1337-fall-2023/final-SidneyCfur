#include "shooter.h"

Roll* Shooter::throw_die(Die& dice1, Die& dice2){
    Roll* roll = new Roll(dice1, dice2);
    roll->roll_die();
    rolls.push_back(roll);
    return roll;
}
Shooter::~Shooter()
{
for(auto i:rolls){
    delete i;
}
}
ostream& operator<<(std::ostream& out, const Shooter& shoot){
    for(auto& i:shoot.rolls){
        out<<i->roll_value()<<"\n";
    }
    return out;
}