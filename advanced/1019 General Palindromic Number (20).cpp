#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> v;
    while (n != 0) {
        v.emplace_back(n % b);
        n /= b;
    }

    bool flag = true;
    for (size_t i = 0, j = v.size() - 1; i < j; ++i, --j) {
        if (v[i] != v[j]) {
            flag = false;
            break;
        }
    }
    string res = flag ? "Yes" : "No";
    cout << res << endl << v.back();
    for (auto i = next(v.rbegin()); i != v.rend(); ++i) cout << ' ' << *i;
}
