#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <limits>
using namespace std;

string getCurrentTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    ostringstream oss;
    oss << setw(2) << setfill('0') << ltm->tm_hour << ":"
        << setw(2) << setfill('0') << ltm->tm_min  << ":"
        << setw(2) << setfill('0') << ltm->tm_sec;
    return oss.str();
}

int getIntInput() {
    int val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  Invalid input. Enter a number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return val;
}
