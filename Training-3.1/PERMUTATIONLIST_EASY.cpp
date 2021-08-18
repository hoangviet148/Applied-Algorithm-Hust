#include <bits/stdc++.h>

using namespace std;

#define N 15
int n;
int temp[N];
bool mark[N];

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            temp[k] = i;
            mark[i] = true;
            if (k == n) {
                for (int j = 1; j <= n; j++) {
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
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);
    cin >> n;
    Try(1);

    return 0;
}