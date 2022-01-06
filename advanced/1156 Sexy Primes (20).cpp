#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i) if (n % i == 0) return false;
    return true;
}

int isSexyPrime(int n) {
    if (isPrime(n)) {
        if (isPrime(n - 6)) return n - 6;
        if (isPrime(n + 6)) return n + 6;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    int res = isSexyPrime(n);
    if (res) {
        cout << "Yes" << endl << res;
        return 0;
    }
    int m = n + 1;
    while (!(res = isSexyPrime(m))) ++m;
    cout << "No" << endl << m;
}
