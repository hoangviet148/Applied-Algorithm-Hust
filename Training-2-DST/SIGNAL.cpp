#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9 + 5;
int n, b;

int main() {
    cin >> n >> b;
    int a[n+2];
    int max_prefix[n+2], max_suffix[n+2];
//    memset(a, 0, n);
//    memset(max_prefix, 0, n);
//    memset(max_suffix, 0, n);
    for (int i = 1; i <= n; i++) cin >> a[i];

    max_prefix[0] = -MAX;
    max_suffix[n + 1] = -MAX;

    for (int i = 1; i <= n; i++) {
        max_prefix[i] = max(max_prefix[i-1], a[i]);
    }

    for (int i = n; i >= 1; i--) {
        max_suffix[i] = max(max_suffix[i+1], a[i]);
    }

    int ans = -1;
    for (int i = 2; i < n; i++) {
        if (max_prefix[i-1] - a[i] >= b && max_suffix[i+1] - a[i] >= b) {
            ans = max(ans, max_prefix[i-1] - a[i] + max_suffix[i+1] - a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
