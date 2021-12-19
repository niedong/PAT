#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull valueOf(const string& s, ull base) {
    ull res = 0, w = 1;
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        int val = isdigit(*i) ? *i - '0' : *i - 'a' + 10;
        res += val * w, w *= base;
    }
    return res;
}

ull search(ull value, const string& s) {
    char ch = *max_element(s.begin(), s.end());
    ull val = isdigit(ch) ? ch - '0' : ch - 'a' + 10;
    ull l = val + 1, r = max(l, value);
    while (l <= r) {
        ull m = (l + r) / 2, c = valueOf(s, m);
        if (c == value) return m;
        if (c < value) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main() {
    string n1, n2;
    ull tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    ull res = tag == 1 ? search(valueOf(n1, radix), n2) : search(valueOf(n2, radix), n1);
    if (res == 0) cout << "Impossible" << endl;
    else cout << res << endl;
}
