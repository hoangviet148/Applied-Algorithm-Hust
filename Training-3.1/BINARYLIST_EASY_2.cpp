#include <bits/stdc++.h>

using namespace std;

int n;
int temp[25];
int stop = 0;

void print() {
    for (int i = 0; i < n; i++) {
        cout << temp[i];
    }
    cout << endl;
}

void genString() {
    int i = n - 1;
    while (i > -1 && temp[i]) {
        temp[i] = 0;
        i--;
    }
    if (i == -1) {
        stop = 1;
    } else {
        temp[i] = 1;
    }
}

void solve() {
    while (!stop) {
        print();
        genString();
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    //freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/0.INP", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++) {
        temp[i] = 0;
    }
    solve();

    return 0;
}