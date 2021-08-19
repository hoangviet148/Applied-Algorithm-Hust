#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int N;
int days[MAX], res[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("../INP.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> days[i];
    }
    sort(days, days + N, greater<int>());
    for (int i = 0; i < N; i++) {
        // cout << days[i];
        res[i] = days[i] + i;
    }
    cout << 2 + *max_element(res, res + N);
    return 0;
}