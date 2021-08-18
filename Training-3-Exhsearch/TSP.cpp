#include <bits/stdc++.h>

using namespace std;

const int N = 405;
int cost[N][N]; // mang chi phi di lai giua cac thanh pho
int temp[N]={0}; // mang luu nhung thanh pho da di qua
bool visited[N] = {false}; // mang danh dau nhung thanh pho da di qua
int n, m;
int c_min = INT_MAX;
int record = INT_MAX; // ki luc
int tempCost = 0; // cost hien tai
int g = 0; // can duoi

void input();
void Try(int k);

int main() {
    ios_base::sync_with_stdio(0);
    freopen("/media/ashley/Data/Hust/Applied-Algorithm/Repo/Training3/0.INP", "r", stdin);

    input();

    temp[1] = 1;
    visited[1] = true;
    Try(2);
    cout << record;
    return 0;
}

void input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cost[i][j] = INT_MAX;
    }

    for (int k = 1; k <= m; k++) {
        int i, j, c;
        cin >> i >> j >> c;
        cost[i][j] = c;
        c_min = min(c_min, c);
    }
}

void Try(int k) {
    for (int i = 1; i <= n; i++) { // xet cac gia tri trong tap phuong an
        if (!visited[i]) {
            temp[k] = i; // cap nhat duong di hien tai
            tempCost += cost[temp[k - 1]][temp[k]]; // cap nhat cost hien tai
            visited[i] = true; // danh dau la da di qua
            if (k == n) {
                record = min(record, tempCost + cost[temp[n]][temp[1]]); // cap nhat lai ki luc
            } else {
                g = tempCost + c_min * (n + 1 - k); // can duoi
                if (g < record) Try(k + 1); // chi tiep tuc xet neu can duoi < ki luc
            }
            tempCost -= cost[temp[k - 1]][temp[k]]; // backtrack
            visited[i] = false;
        }
    }
}
