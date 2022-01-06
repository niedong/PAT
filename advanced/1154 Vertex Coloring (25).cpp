#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int s, d;
        cin >> s >> d;
        graph[s].emplace_back(d);
        graph[d].emplace_back(s);
    }
    int k;
    cin >> k;
    while (k--) {
        vector<int> color(n);
        unordered_set<int> hashset;
        for (int i = 0; i < n; ++i) {
            cin >> color[i];
            hashset.emplace(color[i]);
        }
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                if (color[i] == color[graph[i][j]]) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) cout << "No" << endl;
        else cout << hashset.size() << "-coloring" << endl;
    }
}
