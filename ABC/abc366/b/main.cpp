#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0;
    cin >> n;

    vector<pair<string, int>> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s.at(i).first;
        m = max(m, (int)s.at(i).first.length());
        s.at(i).second = m;
    }

    vector<string> t(m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((int)s.at(n - 1 - j).first.length() <= i) {
                if (i < s.at(n - 1 - j).second) t.at(i) += '*';
            } else {
                t.at(i) += s.at(n - 1 - j).first.at(i);
            }
        }
    }

    for (string t : t) {
        cout << t << endl;
    }

    return 0;
}
