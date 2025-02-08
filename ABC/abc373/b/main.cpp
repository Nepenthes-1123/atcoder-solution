#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, bc = "BCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> s;
    int dis = 0;

    map<char, int> x;

    for (int i = 0; i < 26; ++i) {
        x[s.at(i)] = i + 1;
    }

    int pre = x.at('A');
    for (char c : bc) {
        dis += abs(pre - x.at(c));
        pre = x.at(c);
    }

    cout << dis << endl;

    return 0;
}
