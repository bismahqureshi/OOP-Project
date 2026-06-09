#include "MonthlyReport.h"
#include <iostream>
#include <iomanip>
using namespace std;

MonthlyReport::MonthlyReport(string o, double b) : owner(o), budget(b) {}

void MonthlyReport::addLog(UsageLog l) { logs.push_back(l); }

void MonthlyReport::generate() const {
    double totalKwh = 0, totalCost = 0, wastedKwh = 0, wastedCost = 0;
    for (auto& l : logs) {
        totalKwh += l.kwh; totalCost += l.cost;
        if (l.wasted) { wastedKwh += l.kwh; wastedCost += l.cost; }
    }
    cout << "\n  ====== MONTHLY REPORT — " << owner << " ======\n"
         << "  Total: " << fixed << setprecision(2) << totalKwh << " kWh | "
         << totalCost << " PKR\n"
         << "  Budget: " << budget << " PKR | "
         << (totalCost > budget ? "EXCEEDED" : "Within budget") << "\n"
         << "  Wasted: " << wastedKwh << " kWh | " << wastedCost << " PKR\n\n"
         << "  --- Session Logs ---\n";
    for (auto& l : logs) l.display();
    cout << "\n  Saving tips: ";
    if (wastedCost > 0)
        cout << "Turn off appliances in empty rooms to save ~" << wastedCost << " PKR.\n";
    else
        cout << "No wastage. Great job!\n";
}
