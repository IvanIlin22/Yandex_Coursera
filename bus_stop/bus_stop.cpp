#include <iostream>
#include <map>
#include <vector>

using namespace std;

int                     main() {
    int                 n;
    map<string, vector<string>> new_bus;
    int                 i;

    cin >> n;
    for (i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "NEW_BUS") {
            vector<string>  stop_count;
            int             bus_stop;
            string          bus;
            int             i;
            cin >> bus;
            cin >> bus_stop;
            for (i = 0; i < bus_stop; i++) {
                string str;
                cin >> str;
                stop_count.push_back(str);
            }
            new_bus[bus] = stop_count;
        } else if (operation == "BUSES_FOR_STOP") {
            string stop;
            string ans;
            cin >> stop;
            for (const auto& val : new_bus) {
                for (const auto& halt : val.second) {
                    if (halt == stop) {
                        ans += val.first + " ";
                        break;
                    }
                }
            }
            if (ans == "")
                cout << "No stop" << endl;
            else
                cout << ans << endl;
        } else if (operation == "STOPS_FOR_BUS") {
            string          bus;
            vector<string>  stop;

            cin >> bus;
            if (new_bus.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                stop = new_bus[bus];
                for (const auto& str : stop) {
                    vector<string>  bus_number;
                    for (const auto& val : new_bus) {
                        if (val.first == bus)
                            continue;
                        for (const auto& halt : val.second) {
                            if (halt == str)
                                bus_number.push_back(val.first);
                        }
                    }

                    cout << "Stop " + str + ": ";
                    if (bus_number.empty())
                        cout << "no interchange" << endl;
                    else {
                        for (const auto &val : bus_number) {
                            cout << val << " ";
                        }
                        cout << endl;
                    }
                }
            }
        } else if (operation == "ALL_BUSES") {
            if (new_bus.empty())
                cout << "No buses" << endl;
            else
            {
                for (const auto& val : new_bus) {
                    cout << "Bus " << val.first << ": ";
                    for (const auto& halt : val.second) {
                        cout << halt << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}