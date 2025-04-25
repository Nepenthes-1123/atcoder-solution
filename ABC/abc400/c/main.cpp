#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;

    int64_t l, r, m, ans = 0;
    const int64_t INF = (int64_t)1e9;

    l = 0, r = INF;
    while ((l + 1) < r) {
        m = (l + r) / 2;
        if ((m * m * 2) <= n)
            l = m;
        else
            r = m;
    }
    ans += l;

    l = 0, r = INF;
    while ((l + 1) < r) {
        m = (l + r) / 2;
        if ((m * m * 4) <= n)
            l = m;
        else
            r = m;
    }
    ans += l;

    cout << ans << endl;

    return 0;
}
