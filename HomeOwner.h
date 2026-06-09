#ifndef HOMEOWNER_H
#define HOMEOWNER_H

#include "Room.h"
#include "MonthlyReport.h"
#include <vector>
using namespace std;

class HomeOwner {
    string name, userID;
    double budget;
    vector<Room*>      rooms;
    vector<Appliance*> allAppliances;
    MonthlyReport*     report;
    int appCnt = 0, roomCnt = 0;

    Room*      selectRoom();
    Appliance* selectAppliance(Room* r);
public:
    HomeOwner(string n, string id, double b);
    ~HomeOwner();
    string getName()   const;
    string getUserID() const;
    void addRoom();
    void addAppliance();
    void toggleAppliance();
    void setOccupancy();
    void checkWastage();
    void dashboard() const;
    void showMenu();
};

#endif
