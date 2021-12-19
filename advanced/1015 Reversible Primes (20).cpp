#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    
    for (int i = 2; i < n; ++i) if (n % i == 0) return false;
    return true;
}

int rev(int n, int radix) {
    vector<int> v;
    while (n != 0) {
        v.emplace_back(n % radix);
        n /= radix;
    }
    
    int res = 0, base = 1;
    for (auto i = v.rbegin(); i != v.rend(); ++i) res += *i * base, base *= radix;

    return res;
}

int main() {
    int n, d;
    cin >> n;
    while (n > 0) {
        cin >> d;
        if (isPrime(n) && isPrime(rev(n, d))) cout << "Yes" << endl;
        else cout << "No" << endl;
        cin >> n;
    }
}
