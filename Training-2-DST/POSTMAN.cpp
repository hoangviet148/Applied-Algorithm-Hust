#include <bits/stdc++.h>
using namespace std;

#define N 1002
typedef pair<long long, long long> pll;
long long ans = 0;
pll negCus[N], posCus[N];
// n: num of customer, k: num of package each time
long long n, k;

long long calSegment(pll p[], long long n);

int main() {
    cin >> n >> k;
    long long nn = 0, np = 0; // init position
    for (long long i = 0; i < n; i++) {
        long long x, m;
        cin >> x >> m;
        // divide into 2 group
        if (x < 0) negCus[++nn] = make_pair(x, m);
        else posCus[++np] = make_pair(x, m);
    }
    // sort by customer's position
    sort(negCus + 1, negCus + nn + 1);
    sort(posCus + 1, posCus + np + 1, greater <pll>());

    // calculate min time with each group
    long long negSeg = calSegment(negCus, nn);
    long long posSeg = calSegment(posCus, np);
    ans = negSeg + posSeg;
    cout << ans;

    return 0;
}

long long calSegment(pll p[], long long np) {
    long long res = 0;
    long long cur = 0;
    for (long long i = 1; i <= np; i++) {
        if(p[i].second > 0) {
            if (cur >= p[i].second) {
                // enough package to deliver
                cur -= p[i].second;
            } else {
                // not enough package to deliver
                p[i].second -= cur;
                long long times = (p[i].second - 1) / k + 1;
                res += 2ll * abs(p[i].first) * times;
                cur = times * k - p[i].second;
            }
        }
    }
    return res;
}