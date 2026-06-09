#include "UsageLog.h"
#include <iostream>
#include <iomanip>
using namespace std;

void UsageLog::display() const {
    cout << "  " << appName << " | " << room << " | ON:" << timeOn
         << " OFF:" << timeOff << " | " << fixed << setprecision(2)
         << hours << "hrs | " << kwh << "kWh | " << cost
         << "PKR | Wasted:" << (wasted ? "YES" : "No") << "\n";
}
