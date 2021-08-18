#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    unsigned long long a, b;
    cin >> a >> b;
    cout << ((a % MOD) + (b % MOD)) % MOD;
    return 0;
}
