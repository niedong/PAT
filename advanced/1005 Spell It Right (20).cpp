#include <bits/stdc++.h>

using namespace std;

int main() {
    static const char* map[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    string s;
    cin >> s;

    int sum = 0;

    for (auto const& ch : s) sum += ch - '0';

    if (sum == 0) {
        cout << map[0] << endl;
        return 0;
    }

    vector<string> res;
    while (sum != 0) {
        res.emplace_back(map[sum % 10]);
        sum /= 10;
    }

    cout << res.back();
    for (auto it = next(res.rbegin()); it != res.rend(); ++it) cout << ' ' << *it;
    cout << endl;
}
