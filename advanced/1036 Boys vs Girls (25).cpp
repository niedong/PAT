#include <bits/stdc++.h>

using namespace std;

struct Student {
    Student() = default;
    Student(const string& name, const string& id, int grade) : name(name), id(id), grade(grade) {}

    string name, id;
    int grade;
};

bool compGT(const Student& lhs, const Student& rhs) {
    return lhs.grade > rhs.grade;
}

bool compLT(const Student& lhs, const Student& rhs) {
    return lhs.grade < rhs.grade;
}

int main() {
    int n;
    cin >> n;
    vector<Student> f, m;
    while (n--) {
        string id, gender, name;
        int grade;
        cin >> id >> gender >> name >> grade;
        if (gender == "F") f.emplace_back(id, name, grade);
        else m.emplace_back(id, name, grade);
    }
    sort(f.begin(), f.end(), compGT);
    sort(m.begin(), m.end(), compLT);

    if (f.empty()) cout << "Absent" << endl;
    else cout << f.front().name << ' ' << f.front().id << endl;

    if (m.empty()) cout << "Absent" << endl;
    else cout << m.front().name << ' ' << m.front().id << endl;

    if (f.empty() || m.empty()) cout << "NA" << endl;
    else cout << f.front().grade - m.front().grade << endl;
}
