#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAX = 1000005;
ll n;
ll l[MAX];

ll solution() {
    ll record = INT_MIN;
    for (ll i = 1; i <= n; i++) {
        for (ll j = i; j <= n; j++) {
            ll minValue = INT_MAX;
            for (ll k = i; k <= j; k++) {
                if (l[k] < minValue) minValue = l[k];
            }
            record = max(record, minValue * (j - i + 1));
        }
    }
    return record;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n) {
        if (n == 0) break;
        else {
            for (ll j = 1; j <= n; j++) {
                cin >> l[j];
            }
            cout << solution() << endl;
        }
    }
    return 0;
}