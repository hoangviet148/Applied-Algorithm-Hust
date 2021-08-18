#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005
int n;
int a[MAX], dp[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        dp[i] = max(a[i], dp[i-1] + a[i]);
    }

    cout << *max_element(dp, dp + n);

    return 0;
}