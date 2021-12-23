#include <bits/stdc++.h>

using namespace std;
using tuplessi = tuple<string, string, int>;

template<size_t n>
bool comp(const tuplessi& lhs, const tuplessi& rhs) {
    if constexpr (n == 1 || n == 2) {
        return get<n>(lhs) == get<n>(rhs) ? comp<0>(lhs, rhs) : get<n>(lhs) < get<n>(rhs);
    }
    return get<n>(lhs) < get<n>(rhs);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuplessi> v;
    while (n--) {
        string id, name;
        int grade;
        cin >> id >> name >> grade;
        v.emplace_back(id, name, grade);
    }

    switch(m) {
    case 1:
        sort(v.begin(), v.end(), comp<0>);
        break;
    case 2:
        sort(v.begin(), v.end(), comp<1>);
        break;
    case 3:
        sort(v.begin(), v.end(), comp<2>);
        break;
    default:
        break;
    }

    for (auto const& [id, name, grade] : v) {
        cout << id << ' ' << name << ' ' << grade << endl;
    }
}
