#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<unordered_map<string, set<string>>> v(6);
    string s, d, k;
    int n, q;

    cin >> n;
    while (n--) {
        cin >> s;
        cin.ignore();
        for (int i = 1; i <= 5; ++i) {
            getline(cin, d);
            if (i == 3) {
                stringstream ss(d);
                while (ss >> k) v[i][k].emplace(s);
            }
            else v[i][d].emplace(s);
        }
    }

    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, s), cout << s << endl;

        q = s.front() - '0';
        string r(s.begin() + 3, s.end());

        if (v[q][r].empty()) cout << "Not Found" << endl;
        else {
            for (auto const& id : v[q][r]) cout << id << endl;
        }
    }
}
