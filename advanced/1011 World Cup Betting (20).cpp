#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> v(3);
    double res = 1.0;
    static const char chmap[] = { 'W','T','L' };
    for (int i = 0; i < 3; ++i) {
        cin >> v[0] >> v[1] >> v[2];
        auto m = max_element(v.begin(), v.end());
        auto d = distance(v.begin(), m);
        res *= *m;
        if (i == 0) cout << chmap[d];
        else cout << ' ' << chmap[d];
    }
    res = (res * 0.65 - 1) * 2;
    printf(" %.2lf\n", res);
}
