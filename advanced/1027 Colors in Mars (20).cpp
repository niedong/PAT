#include <bits/stdc++.h>

using namespace std;

string Mars(int c) {
    if (c == 0) return "00";

    string res;
    while (c != 0) {
        int v = c % 13;
        res += v < 10 ? v + '0' : v - 10 + 'A';
        c /= 13;
    }

    if (res.size() == 1) res += '0';
    return string(res.rbegin(), res.rend());
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    cout << '#' << Mars(r) << Mars(g) << Mars(b) << endl;
}
