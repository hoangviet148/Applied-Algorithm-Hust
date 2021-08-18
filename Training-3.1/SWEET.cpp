#include <iostream>

using namespace std;

const long MOD = 1e9 + 7;
const int MAX = 100;
int n, k;
int dp[MAX][MAX];

int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    for (int i = 0; i <= k; i++) {
        for (int j = i; j <= n; j++) {
            if (i == 0 || i == j) dp[i][j] = 1;
            else dp[i][j] = (dp[i][j - 1] % MOD + dp[i - 1][j - 1] % MOD) % MOD;
        }
    }
    return dp[k][n];
}


int main() {
    cin >> n >> k;
    cout << C(n, n + k - 1);
}