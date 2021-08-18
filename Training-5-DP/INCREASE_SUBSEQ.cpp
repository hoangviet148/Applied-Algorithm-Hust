#include <bits/stdc++.h>
using namespace std;

#define MAX 10005
int n;
int a[MAX], dp[MAX] = {-1};
int ans = 0;

int LIS(int i) {
    if (dp[i] != -1) {
        return dp[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) {
            res = max(res, 1 + LIS(j));
        }
    }
    dp[i] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);
    memset(dp, -1, sizeof (dp));

    dp[0] = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    };

    for (int i = 1; i < n; i++) {
        LIS(i);
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}