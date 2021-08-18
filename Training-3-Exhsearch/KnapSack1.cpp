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
int cal();
bool sortByDivision(const pair<int,int> &a, const pair<int,int> &bx) {
    return (1.0 * a.second / a.first) >  (1.0 * bx.second / bx.first);
}

int main() {
    freopen("/home/ashley/Documents/HUST/Applied Algorithm/Repo/Training3/0.INP", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin >> n >> b;
    int w, v;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        wv.emplace_back(w, v);
    }
    sort(wv.begin(), wv.end(), sortByDivision);
    Try(0);
    cout << ans;
    return 0;
}

int cal() {
    tempWeight = tempValue = 0;
    for (int i = 0; i < n; i++) {
        tempWeight += temp[i] * wv[i].first;
        tempValue += temp[i] * wv[i].second;
    }
    if (tempWeight <= b) {
        ans = max(ans, tempValue);
    }
    return ans;
}

void Try(int k) {
    for (int i = 0; i < 2; i++) {
        temp[k] = i;
        if (k == n - 1) {
            record = max(record, cal());
        } else {
            Try(k+1);
        }
    }
}