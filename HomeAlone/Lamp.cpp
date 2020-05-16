#include "Lamp.h"
#include "Lamp.h"


Lamp::Lamp(char house, int unit) : Module(house, unit)
{
    _timeInterval = TimeInterval();
}

TimeInterval* Lamp::getTimeInterval()
{
    return &_timeInterval;
}


void Lamp::setLampTimeInterval(int startHr,int startMin,int endHr,int endMin)
{
    _timeInterval.setStartTime(startHr, startMin);
    _timeInterval.setEndTime(endHr, endMin);
}

string Lamp::getInfo() const
{
    string  s = "Lampe. " ;
    s.append(Module::getInfo());
}


