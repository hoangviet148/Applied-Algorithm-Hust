#include <bits/stdc++.h>
using namespace std;
#define N 100005

int n;
vector<int> adj[N], wei[N];
int d[N]; // d[v] : distance from source node to v
int ans = -1;
int tempIndex = -1;

int bfs(int u);
void init();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n;
    int u, v, w;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        wei[u].push_back(w);
        wei[v].push_back(w);
    }

    init();
    bfs(1);
    init();
    ans = bfs(tempIndex);
    cout << ans;
    return 0;
}

void init() {
    for(int i = 1; i <= n; i++) {
        d[i] = -1;
    }
}

int bfs(int u) {
    int tempMax = -1;
    queue<int> a;
    d[u] = 0;
    a.push(u);
    while (!a.empty()) {
        int tmp = a.front(); a.pop();
        for (int i = 0; i < adj[tmp].size(); i++) {
            int x = adj[tmp][i];
            if (d[x] > -1) continue;
            d[x] = d[tmp] + wei[tmp][i];
            if (d[x] > tempMax) {
                tempMax = d[x];
                tempIndex = x;
            }
            a.push(x);
        }
    }
    int temp = tempMax;
    tempMax = -1;
    return temp;
}