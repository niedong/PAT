#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    unordered_map<int, vector<int>> hashmap;
    for (int i = 0; i < M; ++i) {
        int id, k;
        cin >> id >> k;
        while (k--) {
            int c;
            cin >> c;
            hashmap[id].push_back(c);
        }
    }
    
    vector<int> res(N);

    int depth = 0;
    queue<pair<int, int>> queue;
    queue.push(make_pair(1, 0));
    while (!queue.empty()) {
        auto [i, d] = queue.front();
        queue.pop();
        
        depth = max(depth, d);

        if (hashmap[i].empty()) ++res[d];
        for (auto const& num: hashmap[i]) queue.push(make_pair(num, d + 1));
    }
    
    cout << res.front();
    for (int i = 1; i <= depth; ++i) cout << ' ' << res[i];
    cout << endl;
}
