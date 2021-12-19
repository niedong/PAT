#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> res(1010);
    int K, e;
    double c;
    
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> e >> c;
        res[e] += c;
    }
    
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> e >> c;
        res[e] += c;
    }
    
    int s = 0;
    for (int i = 0; i < res.size(); ++i) if (res[i] != 0) ++s;
    
    cout << s;
    
    for (int i = res.size() - 1; i >= 0; --i) {
        if (res[i] != 0) printf(" %d %.1lf", i, res[i]);
    }
    
    printf("\n");
}
