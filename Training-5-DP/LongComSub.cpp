#include <bits/stdc++.h>
using namespace std;

#define MAX 10005
int n, m;
int x[MAX], y[MAX];
int dp[MAX][MAX];

int LCS(int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int res = 0;
    res = max(res, LCS(i, j -1));
    res = max(res, LCS(i - 1, j));

    if (x[i] == y[j]) {
        res = max(res, 1 + LCS(i - 1, j - 1));
    }
    dp[i][j] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> y[i];
    }

    memset(dp, -1, sizeof (dp));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            LCS(i, j);
        }
    }

    cout << dp[n][m];
    return 0;
}