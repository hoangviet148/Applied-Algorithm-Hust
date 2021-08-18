//#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

const int MAX = 10007;
#define PI 3.14159265358979323846

int T, N, F;
int radius[MAX];
int p[MAX]; // p[i] is number of person who eat pie i

using namespace std;

double getPie(double m) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cnt += (int)floor(PI * radius[i] * radius[i] / m);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    /* FILE* stream;
     freopen_s(&stream, "0.INP", "r", stdin);*/

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> F;
        for (int j = 1; j <= N; j++) {
            cin >> radius[j];
        }
        double l = 0, r = 4e8;
        double eps = 0.000001;
        while (r - l > eps) {
            double m = (l + r) / 2;
            if (getPie(m) > F) l = m;
            else r = m;
        }
        printf("%0.6f\n", l);
    }


    return 0;
}