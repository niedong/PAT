#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = (s.size() + 2) / 3 - 1;
    int m = (s.size() - n * 2);
    string p(m - 2, ' ');
    for (int i = 0; i < n; ++i) {
        cout << s[i] << p;
        cout << s[s.size() - 1 - i] << endl;
    }
    cout << string(s.begin() + n, s.begin() + m + n);
}
