#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <string>
using namespace std;

class Appliance {
protected:
    string name, applianceID, timeOnStamp;
    int    wattage;
    bool   isOn, runningInEmpty;
public:
    Appliance(string id, string n, int w);
    virtual ~Appliance() {}
    virtual double calculateConsumption(double hours) const = 0;
    virtual string getType() const = 0;
    virtual void   displayInfo() const;
    double calculateCost(double h) const;
    void turnOn(bool empty);
    void turnOff();
    string getName()          const;
    string getID()            const;
    string getTimeOnStamp()   const;
    bool   getIsOn()          const;
    bool   isRunningInEmpty() const;
    void   setRunningInEmpty(bool v);
};

#endif
