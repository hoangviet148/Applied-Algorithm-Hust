#include <iostream>

using namespace std;

#define ll long long

ll t[100000];

ll start(ll u) {
    if (u == 1) return 1;
    return t[u] != t[u - 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll N, Q;
    cin >> N;
    ll result = 0;

    for (ll i = 1; i <= N; i++) {
        cin >> t[i];
        result += start(i);
    }

    cin >> Q;
    for (ll i = 1; i <= Q; i++) {
        ll p, c;
        cin >> p >> c;
        result -= start(p);
        if (p < N) result -= start(p + 1);
        t[p] = c;
        result += start(p);
        if (p < N) result += start(p + 1);
        cout << result << endl;
    }
    return 0;
}
