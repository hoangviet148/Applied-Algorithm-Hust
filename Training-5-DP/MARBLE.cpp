#include <bits/stdc++.h>

using namespace std;

#define MAX 605
#define ll long long

ll w, h, n;
ll dp[MAX][MAX]; // dp[i][j] is answer for rectangle i*j


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> w >> h;
    cin >> n;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = i * j;
        }
    }

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        dp[v][u] = 0;
    }

    for (ll i = 1; i <= h; i++) {
        for (ll j = 1; j <= w; j++) {
            ll minWaste = dp[i][j];
            // horizonal cut
            for (ll k = 1; k < i; k++) {
                minWaste = min(minWaste, dp[k][j] + dp[i - k][j]);
            }
            // vertical cut
            for (ll k = 1; k < j; k++) {
                minWaste = min(minWaste, dp[i][k] + dp[i][j - k]);
            }
            dp[i][j] = minWaste;
        }
    }

    cout << dp[h][w] << endl;
    return 0;
}