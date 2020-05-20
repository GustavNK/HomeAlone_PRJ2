#include "Lamp.h"
#include "Lamp.h"


Lamp::Lamp(char house, int unit) : Module(house, unit)
{
    _timeInterval = TimeInterval();
}

string Lamp::getTimeInterval()
{
    string s;
    s.append("Starttidspunkt: ");
    int sh = _timeInterval.getStartTime().getHour();
    s += to_string(sh);
    s.append(":");
    int sm = _timeInterval.getStartTime().getMin();
    if (sm < 10) {
        s += to_string(0);
        s += to_string(sm);
    }
    else {
        s += to_string(sm);
    }

    s.append(". Sluttidspunkt: ");
    int eh = _timeInterval.getEndTime().getHour();
    s += to_string(eh);
    s.append(":");
    int em = _timeInterval.getEndTime().getMin();

    if (em < 10) {
        s += to_string(0);
        s += to_string(em);
    }
    else {
        s += to_string(em);
    }
    s.append(".");
    return s;
}


void Lamp::setLampTimeInterval(int startHr,int startMin,int endHr,int endMin)
{
    _timeInterval.setStartTime(startHr, startMin);
    _timeInterval.setEndTime(endHr, endMin);
}

string Lamp::getInfo()
{
    string  s = "Lampe. " ;
    s.append(Module::getInfo());
    return s; 
}


