#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T = "ATCG";
    cin >> S;

    int len = 0;

    for (int i = 0; i < S.length(); ++i) {
        for (int j = i; j < S.length(); ++j) {
            if (T.find(S.at(j)) == string::npos) {
                break;
            } else {
                len = max(len, j - i + 1);
            }
        }
    }

    cout << len << endl;

    return 0;
}
