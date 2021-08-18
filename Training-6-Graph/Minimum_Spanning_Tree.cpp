#include <bits/stdc++.h>

using namespace std;

const long long N = 100005;

struct edge {
    long long u, v, w;
};

long long V, E;
long long ans = 0;
long long parent[N], ranks[N];

bool compare(const edge &a, const edge &b); // sort by weight
long long find(long long u); // find out which tree u belong to
bool join(long long u, long long v); // combine 2 tree contain u and v

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> V >> E;
    vector<edge> edges(E);
    for (edge &e: edges) {
        cin >> e.u >> e.v >> e.w;
    }

    sort(edges.begin(), edges.end(), compare);

    // init Disjoint set data structure
    for (long long i = 1; i <= V; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }

    for (edge &e: edges) {
        if (join(e.u, e.v)) {
            ans += e.w;
        }
    }

    cout << ans;
    return 0;
}

bool compare(const edge &a, const edge &b) {
    return a.w < b.w;
}

long long find(long long u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

bool join(long long u, long long v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (ranks[u] == ranks[v]) ranks[u]++;
    if (ranks[u] < ranks[v]) {
        parent[u] = v;
    } else parent[v] = u;
    return true;
}