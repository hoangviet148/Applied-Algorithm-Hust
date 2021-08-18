#include <bits/stdc++.h>

#define MAX 25
using namespace std;

int n, N; // num of passengers, num of point
int k; // capacity of bus
int ob = 0; // ob: the number of on-board passengers
int cost[MAX][MAX]; // cost between 2 point
bool visited[MAX]; // mark that point is visited
int c_min = INT_MAX; // value tp compute bound
int tempCost = 0; // current distance
int record = INT_MAX;
int temp[MAX]; // current path

void input();
bool check(int i);
void Try(int v);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/Training3/0.INP", "r", stdin);

    input();
    Try(1);
    cout << record;
}

void input() {
    cin >> n >> k;
    N = n << 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX;
                continue;
            }
            c_min = min (cost[i][j], c_min);
        }
    }
}

bool check(int i) {
    if (visited[i]) return false;
    if (i > n) return visited[i-n];
    if (ob == k && i <= n) return false;
    return true;
}

void Try(int v) {
    for (int i = 1; i <= N; i++) {
        if (check(i)) {
            temp[v] = i;
            tempCost += cost[temp[v-1]][i];
            visited[i] = true;
            if (i > n) ob--;
            else ob++;
            if (v == N) {
                record = min(record, tempCost + cost[temp[N]][0]);
            } else {
                if (tempCost + c_min*(N + 1 - v) < record) Try(v + 1);
            }

            tempCost -= cost[temp[v-1]][i];
            visited[i] = false;
            if (i > n) ob++;
            else ob--;
        }
    }
}