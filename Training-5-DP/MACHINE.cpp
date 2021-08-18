#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

long n;
long s[MAX], t[MAX];
long ans = -1;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (t[i] < s[j] || t[j] < s[i]) {
                ans = max(ans, t[i] - s[i] + t[j] - s[j]);
            }
        }
    }

    cout << ans;
    return 0;
}