#ifndef USAGELOG_H
#define USAGELOG_H

#include <string>
using namespace std;

struct UsageLog {
    string appName, room, timeOn, timeOff;
    double hours, kwh, cost;
    bool   wasted;
    void display() const;
};

#endif
