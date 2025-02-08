#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int64_t> dif(n - 1);

    cin >> a.at(0);

    for (int i = 1; i < n; ++i) {
        cin >> a.at(i);
        dif.at(i - 1) = a.at(i) - a.at(i - 1);
    }

    if (n == 1) {
        cout << 1 << endl;
    } else {
        int64_t ans = 0, pre = dif.at(0), m = 1;
        for (int i = 1; i < n - 1; ++i) {
            if (pre == dif.at(i)) {
                ++m;
            } else {
                ans += (m * m + m) / 2;
                pre = dif.at(i);
                m = 1;
            }
        }

        ans += n + (m * m + m) / 2;

        cout << ans << endl;
    }

    return 0;
}
