#include "HomeOwner.h"
#include "Appliances.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

HomeOwner::HomeOwner(string n, string id, double b) : name(n), userID(id), budget(b) {
    report = new MonthlyReport(n, b);
}

HomeOwner::~HomeOwner() {
    for (auto r : rooms) delete r;
    for (auto a : allAppliances) delete a;
    delete report;
}

string HomeOwner::getName()   const { return name; }
string HomeOwner::getUserID() const { return userID; }

Room* HomeOwner::selectRoom() {
    if (rooms.empty()) { cout << "  No rooms yet.\n"; return nullptr; }
    cout << "\n  Select room:\n";
    for (int i = 0; i < (int)rooms.size(); i++)
        cout << "  " << i + 1 << ". " << rooms[i]->getName()
             << " [" << (rooms[i]->getIsOccupied() ? "OCCUPIED" : "EMPTY") << "]\n";
    cout << "  Enter number: ";
    int ch = getIntInput();
    return (ch >= 1 && ch <= (int)rooms.size()) ? rooms[ch - 1] : nullptr;
}

Appliance* HomeOwner::selectAppliance(Room* r) {
    if (!r || r->applianceCount() == 0) { cout << "  No appliances.\n"; return nullptr; }
    r->displayAppliances();
    cout << "  Enter number: ";
    int ch = getIntInput();
    return (ch >= 1 && ch <= r->applianceCount()) ? r->getAppliances()[ch - 1] : nullptr;
}

void HomeOwner::addRoom() {
    cout << "  Room name: "; string n; getline(cin, n);
    Room* r = new Room("R" + to_string(++roomCnt), n);
    rooms.push_back(r);
    cout << "  [OK] Room added.\n";
}

void HomeOwner::addAppliance() {
    Room* r = selectRoom(); if (!r) return;
    cout << "  1.Fan  2.Light  3.AC\n  Choice: ";
    int t = getIntInput();
    cout << "  Name: "; string n; getline(cin, n);
    string id = "A" + to_string(++appCnt);
    Appliance* ap = nullptr;
    if (t == 1) { cout << "Speed(1-3): "; int s = getIntInput(); ap = new Fan(id, n, s); }
    else if (t == 2) { cout << "1.CFL 2.Regular: "; int b = getIntInput(); ap = new Light(id, n, b == 1); }
    else if (t == 3) { cout << "Temp(16-30): "; int tmp = getIntInput(); ap = new AC(id, n, tmp); }
    else { cout << "Invalid.\n"; return; }
    allAppliances.push_back(ap); r->addAppliance(ap);
}

void HomeOwner::toggleAppliance() {
    Room* r = selectRoom(); if (!r) return;
    Appliance* ap = selectAppliance(r); if (!ap) return;
    cout << "  1.ON  2.OFF: "; int ch = getIntInput();
    if (ch == 1) ap->turnOn(!r->getIsOccupied());
    else if (ch == 2) {
        cout << "  Hours ON: "; double h; cin >> h;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        UsageLog log{ ap->getName(), r->getName(), ap->getTimeOnStamp(),
                      getCurrentTime(), h, ap->calculateConsumption(h),
                      ap->calculateCost(h), ap->isRunningInEmpty() };
        report->addLog(log); ap->turnOff();
    }
}

void HomeOwner::setOccupancy() {
    Room* r = selectRoom(); if (!r) return;
    cout << "  1.Occupied  2.Empty: "; int ch = getIntInput();
    r->setOccupied(ch == 1);
    cout << "  [OK] Updated.\n";
}

void HomeOwner::checkWastage() {
    cout << "  Hours to simulate: "; double h; cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    double total = 0;
    for (auto r : rooms) total += r->checkWastage(h > 0 ? h : 1);
    cout << "  Total wastage: " << fixed << setprecision(2) << total << " PKR\n";
}

void HomeOwner::dashboard() const {
    cout << "\n  === DASHBOARD — " << name << " | Budget: " << budget << " PKR ===\n";
    for (int i = 0; i < (int)rooms.size(); i++) {
        cout << "  " << i + 1 << ". " << rooms[i]->getName()
             << " [" << (rooms[i]->getIsOccupied() ? "OCCUPIED" : "EMPTY") << "]\n";
        rooms[i]->displayAppliances();
    }
}

void HomeOwner::showMenu() {
    int ch = -1;
    while (ch != 0) {
        cout << "\n  1.Dashboard 2.Add Room 3.Add Appliance 4.Toggle Appliance"
             << "\n  5.Set Occupancy 6.Check Wastage 7.Report 0.Logout\n  Choice: ";
        ch = getIntInput();
        switch (ch) {
            case 1: dashboard();        break;
            case 2: addRoom();          break;
            case 3: addAppliance();     break;
            case 4: toggleAppliance();  break;
            case 5: setOccupancy();     break;
            case 6: checkWastage();     break;
            case 7: report->generate(); break;
            case 0: cout << "  Logging out.\n"; break;
        }
    }
}
