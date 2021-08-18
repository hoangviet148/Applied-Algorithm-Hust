#include <bits/stdc++.h>

#define MAX 25
#define MOD 1000000007

using namespace std;

int n, K, Q;
int d[MAX];
int temp[MAX], fac[MAX];
int res = 0;

bool check(int i);

void Try(int v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/Training3/0.INP", "r", stdin);

    cin >> n >> K >> Q;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    fac[0] = 1;
    for (int i = 1; i < n; i++) {
        fac[i] = i * fac[i - 1];
    }

    Try(1);
    cout << res / fac[K];

}

bool check(int i) {

}

void Try(int k) {
    if (k > n) {
        int t = 1;
        for (int k = 1; k <= K; k++) {
            if () return;
            else {
                t = (t * fac[c[k]]) % MOD;
            }
        }
        res = (res + t) % MOD;
        return;
    }

    for (int k = 1; k <= K; k++) {
        if () {

        }
    }
}