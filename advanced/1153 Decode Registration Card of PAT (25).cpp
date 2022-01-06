#include <bits/stdc++.h>

using namespace std;
using pairis = pair<int, string>;

unordered_map<string, int> card_to_score;

bool comp(const string& lhs, const string& rhs) {
    return card_to_score[lhs] == card_to_score[rhs] ?
        lhs < rhs : card_to_score[lhs] > card_to_score[rhs];
}

struct pairiscomp {
    bool operator()(const pairis& lhs, const pairis& rhs) {
        auto const& [ln, ls] = lhs;
        auto const& [rn, rs] = rhs;
        return ln == rn ? ls < rs : ln > rn;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<char, vector<string>> level_to_card;
    unordered_map<string, vector<string>> site_to_card;
    unordered_map<string, unordered_map<string, vector<string>>> date_site_to_card;
    while (n--) {
        string c;
        int s;
        cin >> c >> s;

        card_to_score[c] = s;
        level_to_card[c.front()].emplace_back(c);
        string site(c.begin() + 1, c.begin() + 4), date(c.begin() + 4, c.begin() + 10);
        site_to_card[site].emplace_back(c);
        date_site_to_card[date][site].emplace_back(c);
    }
    for (int i = 1; i <= m; ++i) {
        int type;
        string term;
        cin >> type >> term;
        printf("Case %d: %d %s\n", i, type, term.data());

        switch (type) {
        case 1: {
            char t = term.front();
            sort(level_to_card[t].begin(), level_to_card[t].end(), comp);
            if (level_to_card[t].empty()) printf("NA\n");
            else {
                for (auto const& s : level_to_card[t]) {
                    printf("%s %d\n", s.data(), card_to_score[s]);
                }
            }
            break;
        }
        case 2: {
            int num = site_to_card[term].size();
            if (num == 0) printf("NA\n");
            else {
                int sum = 0;
                for (auto const& s : site_to_card[term]) sum += card_to_score[s];
                printf("%d %d\n", num, sum);
            }
            break;
        }
        case 3: {
            set<pairis, pairiscomp> res;
            for (auto const& [site, v] : date_site_to_card[term]) {
                res.emplace(v.size(), site);
            }
            if (res.empty()) printf("NA\n");
            else {
                for (auto const& [n, s] : res) printf("%s %d\n", s.data(), n);
            }
            break;
        }
        default:
            break;
        }
    }
}
