#include "Appliances.h"
#include <iostream>
#include <algorithm>
using namespace std;

// ── Fan ──────────────────────────────────────────────
Fan::Fan(string id, string n, int s) : Appliance(id, n, 0), speed(s) { setSpeed(s); }

void Fan::setSpeed(int s) {
    speed = max(1, min(3, s));
    wattage = (speed == 1) ? 60 : (speed == 2) ? 80 : 100;
}

double Fan::calculateConsumption(double h) const { return wattage * h / 1000.0; }
string Fan::getType() const { return "FAN"; }

void Fan::displayInfo() const {
    cout << "  [FAN] " << name << " | Speed:" << speed << " | " << wattage
         << "W | " << (isOn ? "ON" : "OFF") << "\n";
}

// ── Light ─────────────────────────────────────────────
Light::Light(string id, string n, bool cfl)
    : Appliance(id, n, cfl ? 15 : 100), isCFL(cfl) {}

double Light::calculateConsumption(double h) const { return wattage * h / 1000.0; }
string Light::getType() const { return "LIGHT"; }

void Light::displayInfo() const {
    cout << "  [LIGHT] " << name << " | " << (isCFL ? "CFL 15W" : "Regular 100W")
         << " | " << (isOn ? "ON" : "OFF") << "\n";
}

// ── AC ───────────────────────────────────────────────
AC::AC(string id, string n, int t) : Appliance(id, n, 1500) { setTemperature(t); }

void AC::setTemperature(int t) {
    temperature = max(16, min(30, t));
    wattage = 1500 + max(0, (24 - temperature)) * 50;
}

double AC::calculateConsumption(double h) const { return wattage * h / 1000.0; }
string AC::getType() const { return "AC"; }

void AC::displayInfo() const {
    cout << "  [AC] " << name << " | " << temperature << "C | "
         << wattage << "W | " << (isOn ? "ON" : "OFF") << "\n";
}
