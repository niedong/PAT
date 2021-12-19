#include <bits/stdc++.h>

using namespace std;

struct person {
    person() = default;
    person(const string& id, int h, int m, int s) : id(id), h(h), m(m), s(s) {}

    string id;
    int h, m, s;
};

int sec(const person& p) {
    return p.h * 3600 + p.m * 60 + p.s;
}

bool compLT(const person& lhs, const person& rhs) {
    return sec(lhs) < sec(rhs);
}

bool compGT(const person& lhs, const person& rhs) {
    return sec(lhs) > sec(rhs);
}

int main() {
    int M;
    vector<person> v1, v2;

    cin >> M;
    while (M--) {
        string id;
        int h, m, s;
        cin >> id;
        scanf("%d:%d:%d", &h, &m, &s);
        v1.emplace_back(id, h, m, s);
        scanf("%d:%d:%d", &h, &m, &s);
        v2.emplace_back(id, h, m, s);
    }

    sort(v1.begin(), v1.end(), compLT);
    sort(v2.begin(), v2.end(), compGT);

    cout << v1.front().id << ' ' << v2.front().id << endl;
}
