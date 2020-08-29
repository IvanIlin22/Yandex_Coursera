#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int                     main() {
    int                 n;
    map<string, int>    m;
    set<vector<string>> s;
    int                 i;

    cin >> n;
    for (i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            vector<string>  s1, s2;
            s1 = {word1, word2};
            s2 = {word2, word1};
            if (!s.count(s1) && !s.count(s2)) {
                s.insert(s1);
                m[word1] += 1;
                m[word2]++;
            }

        } else if (operation == "COUNT") {
            string word;
            cin >> word;
            cout << m[word] << endl;
        } else if (operation == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            vector<string>  s1, s2;
            s1 = {word1, word2};
            s2 = {word2, word1};
            if (s.count(s1) || s.count(s2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

    }

}
