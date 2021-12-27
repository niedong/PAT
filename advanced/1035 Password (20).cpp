#include <bits/stdc++.h>

using namespace std;
using pairss = pair<string, string>;

int main() {
    int n;
    cin >> n;
    vector<pairss> res;
    for (int t = 0; t < n; ++t) {
        string u, p;
        cin >> u >> p;
        bool m = false;
        for (int i = 0; i < p.size(); ++i) {
            switch (p[i]) {
            case '1':
                p[i] = '@';
                m = true;
                break;
            case '0':
                p[i] = '%';
                m = true;
                break;
            case 'l':
                p[i] = 'L';
                m = true;
                break;
            case 'O':
                p[i] = 'o';
                m = true;
                break;
            default:
                break;
            }
        }
        if (m) res.emplace_back(u, p);
    }

    if (res.size()) {
        cout << res.size() << endl;
        for (auto const& [p, u] : res) cout << p << ' ' << u << endl;
    }
    else {
        if (n == 1) printf("There is 1 account and no account is modified\n");
        else printf("There are %d accounts and no account is modified\n", n);
    }
}
