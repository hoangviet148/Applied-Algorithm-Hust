#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int n, m; // n is num of course, m is num of period
int credit[MAX]; // array of credit of each course
int A[MAX][MAX]; // condition
int temp[MAX]; // current path
int load[MAX] = {0}; // load of each period
int record = INT_MAX;
int tempLoad = 0; // current load

void input();
bool check(int i);
void Try(int k);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/Training3/0.INP", "r", stdin);

    input();
    Try(1);
    cout << record;
    return 0;
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> credit[i];
    }

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
}

void solution() {
    int max_load = 0;
    for (int i = 1; i <= m; i++) {
        if (max_load < load[i]) max_load = load[i];
    }
    record = min(record, max_load);
}

bool check(int i, int k) {
    for (int j = 1; j < k; j++) {
        if (A[j][k]) { /// nếu course i phải phân vào một semester trước semester của course k
            if (temp[j] >= i) return false;
        }
        if (A[k][j]) { /// ngược lại
            if (temp[j] <= i) return false;
        }
    }
    return true;
}

void Try(int k) {
    for (int i = 1; i <= m; i++) {
        if (check(i, k)) {
            temp[k] = i;
            tempLoad += credit[k];
            load[i] += credit[k];
            if (k == n) {
                solution();
            } else {
                Try(k + 1);
            }
            tempLoad -= credit[k];
            load[i] -= credit[k];
        }
    }
}