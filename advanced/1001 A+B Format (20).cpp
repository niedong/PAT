#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, sum;
    cin >> a >> b;

    sum = a + b;
    if (sum < 0) sum = -sum, cout << '-';

    string s = to_string(sum), res;

    for (int i = s.size() - 1, j = 1; i >= 0; --i, ++j) {
        res = s[i] + res;
        if (i != 0 && j % 3 == 0) res = ',' + res;
    }

    cout << res << endl;
}
