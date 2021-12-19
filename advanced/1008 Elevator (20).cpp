#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, res = 0, cur = 0;
    cin >> n;
    while (cin >> n) {
        if (n > cur) {
            res += (n - cur) * 6;
            cur = n;
        }
        else if (n < cur) {
            res += (cur - n) * 4;
            cur = n;
        }
        res += 5;
    }
    cout << res << endl;
}
