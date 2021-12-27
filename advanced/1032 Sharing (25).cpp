#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, pair<int, int>> hashmap;
    char data;
    int l, r, n;
    cin >> l >> r >> n;
    if (l == -1 || r == -1) {
        printf("-1\n");
        return 0;
    }

    while (n--) {
        int addr, next;
        cin >> addr >> data >> next;
        hashmap[addr] = make_pair(data, next);
    }

    int u = l, v = r;
    while (u != v) {
        if (u == -1) u = r;
        if (v == -1) v = l;
        u = hashmap[u].second;
        v = hashmap[v].second;
    }
    if (u == -1) printf("-1\n");
    else printf("%05d\n", u);
}
