#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

int N, T, D; // stations, total time to pickup, limit position
int dp[MAX][MAX] = {0};
int a[MAX], t[MAX];
int ans = INT_MIN;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int k = t[i]; k <= T; k++) {
            for (int j = i - 1; j >= max(0,i - D); j--) {
                dp[i][k] = max(dp[i][k], dp[j][k - t[i]] + a[i]);
            }
            ans = max(ans, dp[i][k]);
        }
    }

    cout << ans;
    return 0;
}