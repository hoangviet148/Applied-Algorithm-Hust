/**
 * d(v): độ dài đường đi từ s đến v ngắn nhất hiện biết
 * ( cận trên cho độ dài đường đi ngắn nhất thực sự )
 * p(v): đỉnh đi trước v trong đường đi nói trên
 * (sẽ sử dụng để truy ngược đường đi từ s đến v)
 */
#include<bits/stdc++.h>

using namespace std;
#define MAX 1000005

vector<pair<long long, long long>> a[MAX];
long long n, m; // num of vertex, edge
long long s, t; // start and end vertex

long long find_shortest_path(long long start, long long end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> n >> m;
    long long u, v, k;
    for (long long i = 1; i <= m; i++) {
        cin >> u >> v >> k;
        a[u].emplace_back(v, k);
    }
    cin >> s >> t;
    cout << find_shortest_path(s, t);
    return 0;
}

long long find_shortest_path(long long start, long long end) {
    vector<long long> d(n + 1, 0);
    priority_queue<pair<long long, long long> > vertex_queue;

    // init
    for (long long i = 0; i <= n; i++) {
        d[i] = INT_MAX;
    }
    d[start] = 0;
    vertex_queue.push({-0, start});
    while (!vertex_queue.empty()) { // while T # empty : T la tap dinh co nhan tam thoi
        // tim dinh u thuoc T thoa man d[u] = min {d[z] : z thuoc T}
        pair<long long, int> p = vertex_queue.top();
        vertex_queue.pop();
        long long distance = -p.first;
        int min_vertex = p.second;
        if (d[min_vertex] < distance) { continue; }

        // Gan nhan lai cho cac dinh trong T
        for (auto edge : a[min_vertex]) {
            long long v = edge.first;
            long long w = edge.second;
            if (d[v] > d[min_vertex] + w) {
                d[v] = d[min_vertex] + w;
                vertex_queue.push({-d[v], v});
            }
        }
    }
    return d[end];
}

