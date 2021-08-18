#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000006;

int n, m;
int a[N];

long long getWood(int h) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1ll * max(0, (a[i] - h));
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //FILE* stream;
    //freopen_s(&stream, "0.INP", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int k = *max_element(a + 1, a + n + 1);
    int L = 0;
    int R = k + 1;
    int ans = 0;
    while (R > L + 1) {
        int mid = (L + R) / 2;

        if (getWood(mid) >= m) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    cout << L;
    /* for (int h = 0; h <= k; h++) {
         int sum_wood = get_wood(h);
         if (sum_wood >= m) {
             ans = max(ans, h);
         }
         else {
             break;
         }
     }*/
    //cout << ans;
    return 0;
}