#include <bits/stdc++.h>
using namespace std;

string sKey[12] = {
        "", " abc ", " def ",
        " ghi ", " jkl ", " mno ",
        " pqrs ", " tuv ", " wxyz ",
        "", " ", ""
};

int click[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        int count = 0;
        string sLine;
        getline(cin, sLine);
        for(int j = 0; j < sLine.size(); j++) {
            if (sLine[j] == ' ') count++;
            count += click[sLine[j] - 'a'];
        }
        cout << "Case #" << i + 1 << ": " << count << endl;
    }
    return 0;
}