#include <bits/stdc++.h>

#define ll long long
#define MAX 30

using namespace std;

int N;
int temp[7];
int cnt = 0;
bool visited[MAX];

int check(int i, int k) {
    if (i == 0 && k == 0) {
        return false;
    }
    return true;
}

bool solution() {
    int temp1 = temp[1] * 100000 + temp[2] * 10000 + temp[3] * 1000 + temp[4] * 100 + temp[5] * 10 + temp[2];
    int temp2 = temp[2] * 1000 + temp[2] * 100 + temp[6] * 10 + temp[3];
    return (temp1 + temp2) == N;
}

void Try(int k) {
    for (int i = 0; i <= 9; i++) {
        if (check(i, k) && !visited[i]) {
            temp[k] = i;
            visited[i] = true;
            if (k == 6) {
                if (solution()) cnt++;
            } else {
                Try(k + 1);
            }
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> N;
    Try(1);
    cout << cnt;

    return 0;
}