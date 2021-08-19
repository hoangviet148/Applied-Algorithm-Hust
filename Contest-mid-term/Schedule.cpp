#include <bits/stdc++.h>

#define MAX 20

using namespace std;

int n; // num of course
int a[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n;
    if (n == 1) cout << 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 6 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <n; j++) {
                if (a[i] + a[j] <= 6) {
                    cout << sum / 6;
                    return 0;
                }
            }
            cout << sum / 6 + 1;
        }
    }
    else cout << ceil(1.0 * sum / 6);

    return 0;
}
