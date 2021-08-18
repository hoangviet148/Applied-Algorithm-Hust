#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

int dp[MAX];
int amount[MAX];
int n, L1, L2;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n >> L1 >> L2;
    for (int i = 0; i < n; i++) {
        cin >> amount[i];
        dp[i] = amount[i];
    }

    for (int i = L1; i < n; i++) {
        for (int j = i - L2; j <= i - L1; j++) {
            dp[i] = max(dp[i], dp[j] + amount[i]);
        }
    }

    cout << *max_element(dp, dp + n);
    return 0;
}