#include <iostream>
#include <map>

using namespace std;

void                    CHANGE_CAPITAL(map<string, string> &base, string country, string new_capital) {
    map<string, string> ::  iterator it;
    it = base.find(country);
    if (it == base.end()) {
        base[country] = new_capital;
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    } else if (it->second == new_capital) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
        cout << "Country " << country << " has changed its capital from " << base[country] << " to " << new_capital << endl;
        base[country] = new_capital;
    }
}

void                    RENAME(map<string, string> &base, string old_country_name, string new_country_name) {
    if (old_country_name == new_country_name ||
    base.count(old_country_name) == 0 || base.count(new_country_name) == 1) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        cout << "Country " << old_country_name << " with capital " << base[old_country_name] << " has been renamed to " << new_country_name << endl;
        base[new_country_name] = base[old_country_name];
        base.erase(old_country_name);
    }
}

void                    ABOUT(map<string, string> &base, string country) {
    if (base.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << base[country] << endl;
    }
}

void                DUMP(map<string, string> &base) {
    if (base.empty()) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (const auto& val : base) {
            cout << val.first << "/" << val.second << " ";
        }
        cout << endl;
    }
}

int                     main() {
    int                 n;
    map<string, string> country_capital;
    int                 i;

    cin >> n;
    for (i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "CHANGE_CAPITAL") {
            string country;
            string new_capital;
            cin >> country >> new_capital;
            CHANGE_CAPITAL(country_capital, country, new_capital);
        } else if (operation == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            RENAME(country_capital, old_country_name, new_country_name);
        } else if (operation == "ABOUT") {
            string country;
            cin >> country;
            ABOUT(country_capital, country);
        } else if (operation == "DUMP") {
            DUMP(country_capital);
        }
    }
}