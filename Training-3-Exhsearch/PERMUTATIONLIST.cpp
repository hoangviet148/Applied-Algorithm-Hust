#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const ull MAX = 10005;
ull n, k, a[MAX];
ull ans = 0;

ull gt(ull m) {
    ull res = 1;
    for (ull i = 1; i <= m; i++) {
        res *= i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    if (gt(n) < k && n < 20) {
        cout << -1;
        return 0;
    }

    for (ull i = 1; i <= n; i++) {
        a[i] = i;
    }

    do {
        ans++;
        if (ans == k) {
            for (ull i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            return 0;
        }
    } while (next_permutation(a + 1, a + n + 1));
    return 0;
}