#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, array<int, 4>> rank;
    unordered_map<string, bool> has;
    vector<pair<double, string>> ar;
    vector<pair<int, string>> cr, mr, er;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string id;
        int c, m, e;
        cin >> id >> c >> m >> e;
        has[id] = true;
        ar.emplace_back((c + m + e) / 3.0, id);
        cr.emplace_back(c, id);
        mr.emplace_back(m, id);
        er.emplace_back(e, id);
    }
    sort(ar.begin(), ar.end());
    sort(cr.begin(), cr.end());
    sort(mr.begin(), mr.end());
    sort(er.begin(), er.end());
    
    for (int i = N - 1, r = 1; i >= 0; --i, ++r) {
        if (i == N - 1) {
            get<0>(rank[ar[i].second]) = r;
            get<1>(rank[cr[i].second]) = r;
            get<2>(rank[mr[i].second]) = r;
            get<3>(rank[er[i].second]) = r;
        }
        else {
            get<0>(rank[ar[i].second]) = ar[i].first == ar[i + 1].first ? get<0>(rank[ar[i + 1].second]) : r;
            get<1>(rank[cr[i].second]) = cr[i].first == cr[i + 1].first ? get<1>(rank[cr[i + 1].second]) : r;
            get<2>(rank[mr[i].second]) = mr[i].first == mr[i + 1].first ? get<2>(rank[mr[i + 1].second]) : r;
            get<3>(rank[er[i].second]) = er[i].first == er[i + 1].first ? get<3>(rank[er[i + 1].second]) : r;
        }
    }
    
    while (M--) {
        string id;
        cin >> id;
        if (!has[id]) {
            cout << "N/A" << endl;
            continue;
        }
        
        static constexpr char ch[] = { 'A','C','M','E' };
        auto [a, c, m, e] = rank[id];
        array<int, 4> v({ a,c,m,e });
        auto min = min_element(v.begin(), v.end());
        cout << *min << ' ' << ch[distance(v.begin(), min)] << endl;
    }
}
