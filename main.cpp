#include "HomeOwner.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    vector<HomeOwner*> owners;
    cout << "  === ELECTRICITY WASTE DETECTOR ===\n";
    int ch = -1;
    while (ch != 0) {
        cout << "\n  1.Register  2.Login  0.Exit\n  Choice: ";
        ch = getIntInput();
        if (ch == 1) {
            cout << "  Name: "; string n; getline(cin, n);
            cout << "  Budget (PKR): "; double b; cin >> b;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            HomeOwner* ho = new HomeOwner(n, "HO" + to_string(owners.size() + 1), b < 0 ? 0 : b);
            owners.push_back(ho);
            cout << "  [OK] ID: " << ho->getUserID() << "\n";
            ho->showMenu();
        } else if (ch == 2) {
            cout << "  User ID: "; string id; getline(cin, id);
            for (auto ho : owners)
                if (ho->getUserID() == id) { ho->showMenu(); break; }
        }
    }
    for (auto ho : owners) delete ho;
    cout << "  Goodbye. Save electricity!\n";
    return 0;
}
