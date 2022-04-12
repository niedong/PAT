#include <bits/stdc++.h>

using namespace std;

bool comp(const string& lhs, const string& rhs) {
    return lhs.substr(6, 8) < rhs.substr(6, 8);
}

int main() {
    int n, m, res = 0;
    vector<string> v, g;
    unordered_map<string, bool> hashmap;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        hashmap[s] = true;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (hashmap[s]) {
            ++res;
            v.push_back(s);
        }
        g.push_back(s);
    }

    cout << res << endl;
    if (res) {
        sort(v.begin(), v.end(), comp);
        cout << v.front() << endl;
    }
    else {
        sort(g.begin(), g.end(), comp);
        cout << g.front() << endl;
    }
}
