#include <bits/stdc++.h>

using namespace std;

int input(unordered_map<int, double>& h) {
    int res, k, n;
    double a;

    cin >> k >> n >> a;
    res = n, h[n] = a;
    while (--k) {
        cin >> n >> a;
        h[n] = a;
    }
    return res;
}

int main() {
    unordered_map<int, double> h1, h2;
    int s = input(h1) + input(h2);
    vector<double> res(s + 1);

    for (auto const& p1 : h1) {
        auto [n1, a1] = p1;
        for (auto const& p2 : h2) {
            auto [n2, a2] = p2;
            res[n1 + n2] += a1 * a2;
        }
    }

    int c = 0;

    for (int i = res.size() - 1; i >= 0; --i) if (res[i]) ++c;
    printf("%d", c);
    for (int i = res.size() - 1; i >= 0; --i) if (res[i]) printf(" %d %.1lf", i, res[i]);
}
