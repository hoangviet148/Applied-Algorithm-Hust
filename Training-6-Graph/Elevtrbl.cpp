#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int f, s, g, u, d;
int number[N]; // array contain min number to push button

void bfs(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);

    cin >> f >> s >> g >> u >> d;

    for(int i = 1; i <= f; i++) {
        number[i] = -1;
    }

    bfs(s);

    if (number[g] == -1) cout << "use the stairs";
    else cout << number[g];

    return 0;
}

void bfs(int start) {
    queue <int> a;
    number[start] = 0;
    a.push(start);

    while (!a.empty()) {
        int tmp = a.front(); a.pop();

        if (tmp == g) break;

        // push up
        if (tmp + u <= f && number[tmp + u] == -1) {
            number[tmp + u] = number[tmp] + 1;
            a.push(tmp + u);
        }

        // push down
        if (tmp - d >= 1 && number[tmp - d] == -1) {
            number[tmp - d] = number[tmp] + 1;
            a.push(tmp - d);
        }
    }
}