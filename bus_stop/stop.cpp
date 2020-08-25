#include <iostream>
#include <map>
#include <vector>

using namespace std;

int                     main() {
    int                 n;
    map<vector<string>, int> new_bus;
    int                 i;

    cin >> n;
    for (i = 0; i < n; i++) {
        int             num;
        vector<string>  stop;
        int             j;

        cin >> num;
        for (j = 0; j < num; j++) {
            string  halt;
            cin >> halt;
            stop.push_back(halt);
        }
        if (new_bus.count(stop)) {
            cout << "Already exists for " << new_bus[stop] << endl;
        }
        else {
            new_bus[stop];
            int new_value = new_bus.size();
            new_bus[stop] = new_value;
            cout << "New bus " << new_bus[stop] << endl;
        }
    }
}