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
    vector<long long> visited(n + 1, 0);

    // init
    for (long long i = 0; i <= n; i++) {
        d[i] = INT_MAX;
    }
    d[start] = 0;
    long long step = n;
    while (step--) { // while T # empty : T la tap dinh co nhan tam thoi
        // tim dinh u thuoc T thoa man d[u] = min {d[z] : z thuoc T}
        long long min_vertex = 0;
        for (long long i = 1; i <= n; i++) {
            if (d[min_vertex] > d[i] && visited[i] == false) {
                min_vertex = i;
            }
        }
        visited[min_vertex] = true; // Co dinh nhan cua dinh u

        // Gan nhan lai cho cac dinh trong T
        for (auto edge : a[min_vertex]) {
            long long v = edge.first;
            long long w = edge.second;
            d[v] = min(d[v], d[min_vertex] + w);
        }
    }
    return d[end];
}

