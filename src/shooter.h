#include "roll.h"
#include <vector>
#include <iostream>
using namespace std; using std::vector; using std::string;

#ifndef SHOOTER_H
#define SHOOTER_H
class Shooter 
{
friend ostream& operator<<(std::ostream& out, const Shooter& shoot);
public:
Roll* throw_die(Die& dice1, Die& dice2);
~Shooter();
private:
vector<Roll*> rolls;
};
#endif