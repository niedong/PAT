#include <bits/stdc++.h>

using namespace std;

int main () {
    int K;
    cin >> K;
    vector<int> v(K);
    for (int i = 0; i < K; ++i) cin >> v[i];

    vector<tuple<int, int, int>> dp(K);
    dp.front() = make_tuple(v.front(), 0, 0);
    int res = v.front();

    for (int i = 1; i < K; ++i) {
        auto [s, l, r] = dp[i - 1];
        if (s + v[i] > v[i]) {
            dp[i] = make_tuple(s + v[i], l, i);
            res = max(res, s + v[i]);
        }

        else if (s + v[i] < v[i]) {
            dp[i] = make_tuple(v[i], i, i);
            res = max(res, v[i]);
        }
    }

    for (int i = 0; i < dp.size(); ++i) {
        auto [s, l, r] = dp[i];
        if (s == res && res >= 0) {
            printf("%d %d %d\n", s, v[l], v[r]);
            return 0;
        }
    }

    printf("%d %d %d\n", 0, v.front(), v.back());
}
