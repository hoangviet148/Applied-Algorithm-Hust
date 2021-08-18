#include <bits/stdc++.h>

using namespace std;

const int N = 35;
int m, n; // num of teacher, num of course
int k; // num of conflict course
vector<int> teach[N]; // contain list teacher of each course
int conflict[N][N] = {0}; // contain list conflict course of each course
int temp[N] = {0}; // array contain current path
int cnt[N] = {0}; // array contain current number of course of teacher
int record = INT_MAX;

void input();
void Try(int v);

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("/media/ashley/Data/Hust/Applied-Algorithm/Repo/Training3/0.INP", "r", stdin);

    input();
    Try(1);
    record = (record == INT_MAX) ? -1 : record;
    cout << record;
    return 0;
}

void input() {
    cin >> m >> n;
    int num;
    for (int i = 1; i <= m; i++) {
        cin >> num;
        int p;
        for (int j = 1; j <= num; j++) {
            cin >> p;
            teach[p].push_back(i);
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        conflict[u][v] = 1;
        conflict[v][u] = 1;
    }
}

void Try(int v) {
    for (int teacher : teach[v]) { // travel each teacher in course k
        bool canAssign = true;
        for (int i = 1; i <= v; i++) { // xet cac mon hoc da duyet
            // neu co mon hoc nam trong danh sach cua giao vien teacher thi stop
            if (conflict[v][i] && temp[i] == teacher) {
                canAssign = false;
                break;
            }
        }
        if (canAssign) {
            temp[v] = teacher;
            cnt[teacher]++;
            if (v == n) {
                // update record
                int maxLoad = *max_element(cnt + 1, cnt + m + 1);
                record = min(record, maxLoad);
            } else {
                // nhanh can de giam so lan de quy
                if (cnt[teacher] < record) Try(v + 1);
            }
            temp[v] = 0; // backtrack
            cnt[teacher]--;
        }
    }
}
