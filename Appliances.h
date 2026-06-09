#ifndef APPLIANCES_H
#define APPLIANCES_H

#include "Appliance.h"
using namespace std;

// ── Fan ──────────────────────────────────────────────
class Fan : public Appliance {
    int speed;
public:
    Fan(string id, string n, int s = 2);
    void setSpeed(int s);
    double calculateConsumption(double h) const override;
    string getType() const override;
    void displayInfo() const override;
};

// ── Light ─────────────────────────────────────────────
class Light : public Appliance {
    bool isCFL;
public:
    Light(string id, string n, bool cfl = true);
    double calculateConsumption(double h) const override;
    string getType() const override;
    void displayInfo() const override;
};

// ── AC ───────────────────────────────────────────────
class AC : public Appliance {
    int temperature;
public:
    AC(string id, string n, int t = 24);
    void setTemperature(int t);
    double calculateConsumption(double h) const override;
    string getType() const override;
    void displayInfo() const override;
};

#endif
