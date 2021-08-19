#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005
#define MOD 1000000007

long long n;
long long a[MAX], dp[MAX];
long long ans = 0;

long long LIS(long long i) {
    if (dp[i] != -1) {
        return dp[i];
    }
    long long res = 1;
    for (long long j = 0; j < i; j++) {
        if (abs(a[j]) < abs(a[i]) && (a[i]*a[j]) % MOD < 0) {
            res = max(res, 1 + LIS(j));
        }
    }
    dp[i] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);
    memset(dp, -1, sizeof (dp));

    dp[0] = 1;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    };

    for (long long i = 1; i < n; i++) {
        LIS(i);
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}