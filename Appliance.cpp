#include "Appliance.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

Appliance::Appliance(string id, string n, int w)
    : applianceID(id), name(n), wattage(w), isOn(false), runningInEmpty(false) {}

void Appliance::displayInfo() const {
    cout << "  [" << getType() << "] " << name << " | " << wattage
         << "W | " << (isOn ? "ON" : "OFF") << "\n";
}

double Appliance::calculateCost(double h) const {
    return calculateConsumption(h) * 30.0;
}

void Appliance::turnOn(bool empty) {
    if (isOn) { cout << "  [!] Already ON.\n"; return; }
    isOn = true; runningInEmpty = empty;
    timeOnStamp = getCurrentTime();
    cout << "  [OK] " << name << " ON at " << timeOnStamp << "\n";
    if (empty) cout << "  [!!] WARNING: Room EMPTY — logged as WASTAGE.\n";
}

void Appliance::turnOff() {
    if (!isOn) { cout << "  [!] Already OFF.\n"; return; }
    isOn = false;
    cout << "  [OK] " << name << " OFF at " << getCurrentTime() << "\n";
}

string Appliance::getName()          const { return name; }
string Appliance::getID()            const { return applianceID; }
string Appliance::getTimeOnStamp()   const { return timeOnStamp; }
bool   Appliance::getIsOn()          const { return isOn; }
bool   Appliance::isRunningInEmpty() const { return runningInEmpty; }
void   Appliance::setRunningInEmpty(bool v) { runningInEmpty = v; }
