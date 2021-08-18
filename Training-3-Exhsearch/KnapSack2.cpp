#include<bits/stdc++.h>

using namespace std;
const int N = 35;

int n, b; // n is number of item and b is max weight
vector<pair<int, int>> wv;
int temp[N]; // mang sinh cac chuoi gia tri nhi phan
int tempWeight, tempValue;
int ans = 0; // ket qua cua bai toan
int record = INT_MIN;

void Try(int k);
int cal(int k);
bool sortByDivision(const pair<int,int> &a, const pair<int,int> &bx) {
    return (1.0 * a.second / a.first) >  (1.0 * bx.second / bx.first);
}

int main() {
    // freopen("/home/ashley/Documents/HUST/Applied Algorithm/Repo/Training3/0.INP", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin >> n >> b;
    int w, v;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        wv.emplace_back(w, v);
    }
    sort(wv.begin(), wv.end(), sortByDivision);
    Try(0);
    cout << record;
    return 0;
}

void Try(int k) {
    for (int i = 1; i >= 0; i--) {
        temp[k] = i;
        tempWeight += temp[k] * wv[k].first;
        tempValue += temp[k] * wv[k].second;
        if (k == n - 1 && tempWeight <= b) {
            record = max(record, tempValue);
        } else {
            int bk = b - tempWeight;
            double g = tempValue + bk * (1.0 * wv[k+1].second / wv[k+1].first);
            if ((bk >= 0) && (g > record)) Try(k+1);
            //Try(k+1);
        }
        tempWeight -= temp[k] * wv[k].first;
        tempValue -= temp[k] * wv[k].second;
    }
}