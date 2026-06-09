#include "Room.h"
#include <iostream>
#include <iomanip>
using namespace std;

Room::Room(string id, string n) : roomID(id), name(n), isOccupied(false) {}

void Room::setOccupied(bool s) {
    isOccupied = s;
    if (!s)
        for (auto a : appliances)
            if (a->getIsOn()) a->setRunningInEmpty(true);
}

void Room::addAppliance(Appliance* a) {
    appliances.push_back(a);
    cout << "  [OK] " << a->getName() << " added to '" << name << "'.\n";
}

double Room::checkWastage(double h) const {
    double total = 0;
    cout << "\n  === WASTAGE: " << name << " [" << (isOccupied ? "OCCUPIED" : "EMPTY") << "] ===\n";
    for (auto a : appliances) {
        if (a->getIsOn() && !isOccupied) {
            double cost = a->calculateCost(h);
            total += cost;
            cout << "  [!!] WASTE: " << a->getName() << " | "
                 << fixed << setprecision(2) << cost << " PKR\n";
        }
    }
    if (total == 0) cout << "  [OK] No wastage.\n";
    return total;
}

void Room::displayAppliances() const {
    if (appliances.empty()) { cout << "  (none)\n"; return; }
    for (int i = 0; i < (int)appliances.size(); i++) {
        cout << "  " << (i + 1) << ". ";
        appliances[i]->displayInfo();
    }
}

string             Room::getName()        const { return name; }
string             Room::getID()          const { return roomID; }
bool               Room::getIsOccupied()  const { return isOccupied; }
int                Room::applianceCount() const { return appliances.size(); }
vector<Appliance*>& Room::getAppliances()       { return appliances; }
