#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n;
int a[MAX];

//int main() {
//    cin >> n;
//    int a[n+2];
//    int max_prefix[n+2], max_suffix[n+2];
////    memset(a, 0, n);
////    memset(max_prefix, 0, n);
////    memset(max_suffix, 0, n);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//
//    max_prefix[0] = -MAX;
//    max_suffix[n + 1] = -MAX;
//
//    for (int i = 1; i <= n; i++) {
//        max_prefix[i] = max(max_prefix[i-1], a[i]);
//    }
//
//    for (int i = n; i >= 1; i--) {
//        max_suffix[i] = max(max_suffix[i+1], a[i]);
//    }
//
//    int minEle = *min_element(a, a + n);
//    for (int i = 0; i < n; i ++) {
//
//    }
//
//    int ans = -1;
////    for (int i = 2; i < n; i++) {
////        if (max_prefix[i-1] - a[i] >= b && max_suffix[i+1] - a[i] >= b) {
////            ans = max(ans, max_prefix[i-1] - a[i] + max_suffix[i+1] - a[i]);
////        }
////    }
//
//    cout << ans << endl;
//    return 0;
//}

int main() {
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/untitled/0.INP", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int Min = INT_MAX;
    int Max = INT_MIN;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i-1] && a[i] < a[i+1]) {
            Min = min(Min, a[i]);
        }
        if (a[i] > a[i-1] && a[i] > a[i+1]) {
            Max = max(Max, a[i]);
        }
    }
    cout << Max << " " << Min;

}