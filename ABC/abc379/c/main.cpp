#include <bits/stdc++.h>
using namespace std;

int count(int x, int dif) { return (x + (x - dif + 1)) * dif / 2; }

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> X(m);
    vector<int64_t> A(m);
    vector<pair<int, int64_t>> XA(m);

    for (int i = 0; i < m; ++i) {
        cin >> XA.at(i).first;
    }

    for (int i = 0; i < m; ++i) {
        cin >> XA.at(i).second;
    }

    sort(XA.begin(), XA.end());

    // count
    int64_t over = 0, ans = 0;
    for (int i = 0; i < m; ++i) {
        int x = XA.at(i).first, dif;
        int64_t a = XA.at(i).second;

        if (i == 0 && x != 1) {
            cout << -1 << endl;
            return 0;
        }

        dif = i + 1 < m ? X.at(i + 1) - x : (n + 1) - x;

        a += over;

        if (dif > a) {
            cout << -1 << endl;
            return 0;
        } else if (i + 1 == m && dif != a) {
            cout << -1 << endl;
            return 0;
        } else {
            ans += count(a - 1, dif);
        }

        over = a - dif;
    }

    // output
    cout << ans << endl;
    return 0;
}
