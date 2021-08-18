#include <bits/stdc++.h>

using namespace std;

#define MAX 10005
int N, K1, K2;
int cnt = 0;
int temp[MAX];

bool check(int i) {
    for (int j = i - K2; j <= i - K1; j++) {
        if (temp[j] == 0) return true;
    }
    return false;
}

void Try(int k) {
    for (int i = 0; i <= 1 - temp[k - 1]; i++) {
        if (check(i)) {
            temp[k] = i;
            if (k == N) {
                cnt++;
            } else Try(k + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> N >> K1 >> K2;
    Try(1);

    cout << cnt;
    return 0;
}