#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int maxSum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if(sum < 0) sum = 0;
        maxSum = max(sum, maxSum);
    }
    cout << maxSum;
    return 0;
}
