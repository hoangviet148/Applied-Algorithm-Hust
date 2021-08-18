#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
vector<pair<int, int>> adj[N];
bool is_bridge[N], used[N];
int num[N]; // traversal order of vertex u when dfs
int low[N]; // low[u] = min num[u] in sub DFS forest of vertex u
int cnt = 0; // count dfs order of vertexes

void Tarjan(int u, int p);
int DFS(int u);

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].emplace_back(v, i); // save edge index to trace easily
        adj[v].emplace_back(u, i);
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            Tarjan(i, 0);
        }
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int c = DFS(i);
            res += 1ll * c * (c - 1) / 2 - (c - 1);
        }
    }
    cout << res;
    return 0;
}

void Tarjan(int u, int p) {
    num[u] = low[u] = ++cnt;
    // traversal neighbor of u
    for(auto & i : adj[u]) {
        int v = i.first; // neighbor
        int w = i.second; // index
        if (v == p) continue;
        if(num[v]) {
            low[u] = min(low[u], low[v]);
        } else {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > num[u]) is_bridge[w] = true;
        }
    }
}

int DFS(int u) {
    used[u] = true;
    int res = 1;
    for (auto & i : adj[u]) {
        int v = i.first;
        int w = i.second;
        if (!is_bridge[w]) continue;
        if (!used[v]) {
            res += DFS(v);
        }
    }
    return res;
}