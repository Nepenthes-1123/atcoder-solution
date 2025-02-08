#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, s_edi;
    cin >> s;

    for (char c : s) {
        if (c != '.') s_edi += c;
    }

    cout << s_edi << endl;

    return 0;
}
