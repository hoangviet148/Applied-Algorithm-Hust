#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
vector<int> adj[N];
int cnt = 0;
bool visited[N];

void dfs(int u);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n;
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) cnt++;
    }
    cout << cnt;
    return 0;
}

void dfs(int u) {
    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
            dfs(v);
        }
    }
}