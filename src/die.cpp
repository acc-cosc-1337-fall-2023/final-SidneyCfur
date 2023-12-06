#include "die.h"

void Die::roll()
{
roll_value = 1 + (rand() % sides);
}

