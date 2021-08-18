#include<bits/stdc++.h>
using namespace std;
#define MAX 2005

vector<int> a[MAX];
int mark[MAX];

void DFS(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (!mark[v]) {
            mark[v] = -mark[u];
            DFS(v);
        }
    }
}

void solve(int n) {
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            mark[i] = 1;
            DFS(i);
        }
    }
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (mark[i] == mark[a[i][j]]) {
                ans = false;
                break;
            }
        }
    }

    if (ans) {
        cout << "No suspicious bugs found!" << endl;
    } else {
        cout << "Suspicious bugs found!" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int u, v;
        cin >> u >> v;
        for (int j = 1; j <= u; j++) {
            a[j].clear();
        }
        memset(mark, 0, sizeof (mark));

        for (int k = 1; k <= v; k++) {
            int m, n;
            cin >> m >> n;
            a[m].push_back(n);
            a[n].push_back(m);
        }
        cout << "Scenario #" << i << ":" << endl;
        solve(u);
    }
    return 0;
}