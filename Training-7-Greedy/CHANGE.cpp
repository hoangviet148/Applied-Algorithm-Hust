#include <bits/stdc++.h>
using namespace std;

int currency[6] = {500, 100, 50, 10, 5, 1};
int N, change, res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("../INP.txt", "r", stdin);
    cin >> N;
    change = 1000 - N;
    for (int i : currency) {
        if (change == 0) break;
        res += change / i;
        change %= i;
    }
    cout << res;
    return 0;
}
