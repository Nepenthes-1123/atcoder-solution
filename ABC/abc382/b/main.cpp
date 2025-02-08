#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    string s;

    cin >> n >> d >> s;

    int cnt = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (s.at(i) == '@') {
            s.at(i) = '.';
            ++cnt;
        }
        if (d == cnt) break;
    }

    cout << s << endl;

    return 0;
}
