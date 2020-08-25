#include <iostream>
#include <map>

using namespace std;

map<char, int>      BuildCharCounters(string str) {
    map<char, int>  m;

    for (const auto& val : str) {
        m[val]++;
    }
    return m;
}

int                 main() {
    int             n;
    string          first_string;
    string          second_string;
    int             i;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> first_string >> second_string;
        if (BuildCharCounters(first_string) == BuildCharCounters(second_string))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
