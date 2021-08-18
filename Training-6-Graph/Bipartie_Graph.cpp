#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

vector<int> adj[MAX];
int mark[MAX];
int n , m; // vertex, edge

bool dfs(int i, int color);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= v; i++) {
        if (mark[i]) continue;
        if (!dfs(i, 1)) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}

bool dfs(int u, int color = 1) {
    mark[u] = color;

    int ans = true;
    for (int v : adj[u]) {
        if (!mark[v] && !dfs(v, 3 - mark[u])) ans = false;
        if (mark[v] == color) ans = false;
    }
    return ans;
}