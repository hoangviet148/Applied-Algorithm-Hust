#include <bits/stdc++.h>

using namespace std;
#define N 15

int n, K;
bool mark[N];
int temp[N];
bool p[N][N];
int cnt = 0;

void print() {
    cnt++;
    for (int i = 1; i <= n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

bool check(int i, int k) {
    if (mark[i]) return false;
    for (int j = 1; j < k; j++) {
        if (p[i][temp[j]]) return false;
    }
    return true;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (check(i, k)) {
            temp[k] = i;
            mark[i] = true;
            if (k == n) {
                print();
            } else Try(k + 1);
            mark[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);
    cin >> n >> K;

    int u, v;
    for (int i = 1; i <= K; i++) {
        cin >> u >> v;
        p[u][v] = true;
    }
    Try(1);

    cout << cnt;
    return 0;
}