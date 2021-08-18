#include <bits/stdc++.h>

using namespace std;
#define N 100005

int n, m;
vector<int> adj[N];
int num[N], parent[N], low[N];

void dfs(int u);
int countArticulation();
int countBridge();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs(i);
    }
    cout << countArticulation() << " " << countBridge();
    return 0;
}

void dfs(int u) {
    num[u] = ++num[0];
    low[u] = N;
    for (auto v : adj[u]) {
        if (v == parent[u]) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
}

int countArticulation() {
    int articulation[N] = {0}, child[N] = {0};
    for (int v = 1; v <= n; v++) {
        int u = parent[v];
        if (u > 0) child[u]++;
    }

    for (int v = 1; v <= n; v++) {
        int u = parent[v];
        if (u > 0 && parent[u] > 0 && low[v] >= num[u]) articulation[u] = 1;
    }

    for (int u = 1; u <= n; u++) {
        if (parent[u] == 0 && child[u] >= 2) articulation[u] = 1;
    }

    for (int u = 1; u <= n; u++) {
        articulation[0] += articulation[u] == 1;
    }

    return articulation[0];
}

int countBridge() {
    int bridges = 0;
    for (int v = 1; v <= n; v++) {
        bridges += parent[v] > 0 && low[v] >= num[v];
    }
    return bridges;
}

// https://vnspoj.github.io/problems/GRAPH_.html