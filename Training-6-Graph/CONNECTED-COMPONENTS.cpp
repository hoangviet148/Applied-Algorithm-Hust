#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int N, M;
vector<int> a[MAX];
int visited[MAX];
int ans;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void init() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void dfs(int u) {
    for (int v : a[u]) {
        if (!visited[v]) {
            visited[v] = 1;
            dfs(v);
        }
    }
}

void solve() {
    init();
    ans = 0;
    for (int v = 1; v <= N; v++) {
        if (!visited[v]) {
            ans++;
            dfs(v);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    input();
    solve();

    return 0;
}