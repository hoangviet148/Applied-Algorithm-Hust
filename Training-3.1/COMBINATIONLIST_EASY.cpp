#include <bits/stdc++.h>

using namespace std;

#define N 15
int n, m;
int temp[N];
bool mark[N];

bool check(int i, int k) {
    if (!mark[i] && i > temp[k-1]) return true;
    return false;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (check(i, k)) {
            temp[k] = i;
            mark[i] = true;
            if (k == m) {
                for (int j = 1; j <= m; j++) {
                    cout << temp[j] << " ";
                }
                cout << endl;
            } else Try(k + 1);
            mark[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);
    cin >> n >> m;

    Try(1);

    return 0;
}