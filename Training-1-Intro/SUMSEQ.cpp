#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long res = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        res = ((res % MOD) + (a[i] % MOD)) % MOD;
    }
    cout << res;
    return 0;
}
