// 此题有O(log(n + m))的解法，待更新

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, v;
    vector<int> vn, vm;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        vn.emplace_back(v);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> v;
        vm.emplace_back(v);
    }

    vector<int> va(n + m);
    merge(vn.begin(), vn.end(), vm.begin(), vm.end(), va.begin());

    int res = va.size() % 2 == 0 ? va[va.size() / 2 - 1] : va[va.size() / 2];
    cout << res << endl;
}
