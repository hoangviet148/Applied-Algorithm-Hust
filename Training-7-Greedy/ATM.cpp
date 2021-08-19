#include <bits/stdc++.h>
using namespace std;

long long w ,c, T;
int n_way[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};
int n_coin[] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../INP.txt", "r", stdin);

    int n_test;
    cin >> n_test;
    for(int i = 1; i <= n_test; i++) {
        cin >> w >> c;
        if (w % 1000) {
            cout << 0 << endl;
            continue;
        }

        w /= 1000;
        int t;
        long long num_coin = 0;
        long long num_way = 1;
        for(int i = 0; i < c; i++) {
            if(w == 0) break;
            t = w % 10;
            num_way *= n_way[t];
            num_coin += n_coin[t];
            w /= 10;
        }

        t = w % 10;
        num_coin += n_coin[t];
        w /= 10;
        if (w != 0 && (t == 1 || t == 4)) {
            num_way *= n_way[t + 5];
        } else {
            num_way *= n_way[t];
        }

        if (w != 0) {
            num_coin += w * 2;
        }
        cout << num_coin << " " << num_way << endl;
    }
    return 0;
}