#ifndef ROOM_H
#define ROOM_H

#include "Appliance.h"
#include <vector>
using namespace std;

class Room {
    string roomID, name;
    bool   isOccupied;
    vector<Appliance*> appliances;
public:
    Room(string id, string n);
    void setOccupied(bool s);
    void addAppliance(Appliance* a);
    double checkWastage(double h) const;
    void displayAppliances() const;
    string             getName()        const;
    string             getID()          const;
    bool               getIsOccupied()  const;
    int                applianceCount() const;
    vector<Appliance*>& getAppliances();
};

#endif
