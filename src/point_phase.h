#include "phase.h"
class PointPhase : public Phase{
public:
PointPhase(int p):point(p){}
RollOutcome get_outcome(Roll* roll);
private:
int point;
};