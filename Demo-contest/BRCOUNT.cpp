#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
const int MOD = 1000000007;

bool checkValid(string s) {
    stack<char> st;
    if (s[0] == ')') return false;
    for (auto c : s) {
        if (c == '(') st.push(c);
        else {
            if (!st.empty()) st.pop();
            else return false;
        }
    }
    return st.empty();
}

int main() {
    freopen("/home/ashley/Documents/Hust/Applied-Algorithm/Repo/untitled/0.INP", "r", stdin);
    string str;
    int qm = 0, ob = 0, cb = 0; // num of ?, (, )

    cin >> str;
    int len = str.length();
    for (auto c : str) {
        if (c == '?') qm++;
        if (c == '(') ob++;
        if (c == ')') cb++;
    }
    int numOfOb = len / 2 - ob;
    int numOfCb = len / 2 - cb;
    string subStr = "";
    for (int i = 0; i < numOfOb; i++) {
        subStr += '(';
    }
    for (int i = 0; i < numOfCb; i++) {
        subStr += ')';
    }

    do {
        string temp = str;
        int i = 0;
        for (int j = 0; j < len; j++) {
            if (temp[j] == '?') {
                temp[j] = subStr[i];
                i++;
            }
        }
        if (checkValid(temp)) cnt++;
    } while (next_permutation(subStr.begin(), subStr.end()));

    cout << cnt % MOD;
    return 0;
}