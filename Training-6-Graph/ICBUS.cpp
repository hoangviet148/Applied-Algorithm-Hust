#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e3+5;
int N, K;
vector <int> a[MAX];
vector <int> b[MAX];
pair <int, int> p[MAX];
typedef pair <int, int> pai;
int visited[MAX];
int minh;
int flg[MAX], dist[MAX][MAX];
queue<int> Q;
priority_queue<pai, vector<pai>, greater<pai>> pq;
vector <long long> d(MAX, 2e8);

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 1; i <= K; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    pq.push(make_pair(0, 1));
    d[1] = 0;
}

void getAllAdjacent(int u) {
    for (int i = 0; i <= N; i++) {
        flg[i] = 0;
    }
    Q.push(u);
    flg[u] = 1;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int x : a[v]) {
            if (flg[x] == 0) {
                flg[x] = flg[v] + 1;
                dist[u][x] = p[u].first;
                b[u].push_back(x);
                if (flg[x] - 1 < p[u].second) Q.push(x);
            }
        }
    }
}

void buildGraph() {
    for (int v = 1; v <= N; v++) {
        for (int i = 1; i <= N; i++) {
            visited[i] = 0;
        }
        minh = v;
        visited[v] = 1;
        getAllAdjacent(v);
    }
}

void findShortestPath() {
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < b[u].size(); i++) {
            int v = b[u][i];
            if (d[v] > d[u] + dist[u][v]) {
                d[v] = d[u] + dist[u][v];
                pq.push(make_pair(d[v], v));
            }
        }
    }
    cout << d[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    input();
    buildGraph();
    findShortestPath();
    return 0;
}