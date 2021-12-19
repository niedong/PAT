#include <bits/stdc++.h>

using namespace std;
using pairsi = pair<string, int>;

bool comp(const pairsi& lhs, const pairsi& rhs) {
    return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second > rhs.second;
}

int main() {
    int n, k;
    cin >> n;
    vector<vector<pairsi>> v(n + 1);
    vector<pairsi> all;
    unordered_map<string, int> belong, ar;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        while (k--) {
            string id;
            int score;
            cin >> id >> score;
            v[i].emplace_back(id, score), all.emplace_back(id, score);
            belong[id] = i;
        }
    }

    vector<unordered_map<string, int>> lr(n + 1);
    for (int i = 1; i <= n; ++i) {
        sort(v[i].begin(), v[i].end(), comp);
        lr[i][v[i].front().first] = 1;
        
        for (int j = 1; j < v[i].size(); ++j) {
            lr[i][v[i][j].first] = v[i][j].second == v[i][j - 1].second ? lr[i][v[i][j - 1].first] : j + 1;
        }
    }

    sort(all.begin(), all.end(), comp);
    ar[all.front().first] = 1;

    for (int j = 1; j < all.size(); ++j) {
        ar[all[j].first] = all[j].second == all[j - 1].second ? ar[all[j - 1].first] : j + 1;
    }

    cout << all.size() << endl;
    for (auto const& p : all) {
        auto& id = p.first;
        cout << id << ' ' << ar[id] << ' ' << belong[id] << ' ' << lr[belong[id]][id] << endl;
    }
}
