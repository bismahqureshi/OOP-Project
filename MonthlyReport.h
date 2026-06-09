#ifndef MONTHLYREPORT_H
#define MONTHLYREPORT_H

#include "UsageLog.h"
#include <vector>
using namespace std;

class MonthlyReport {
    vector<UsageLog> logs;
    string owner;
    double budget;
public:
    MonthlyReport(string o, double b);
    void addLog(UsageLog l);
    void generate() const;
};

#endif
