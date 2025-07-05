#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    deque<pair<int64_t, int64_t>> a;

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int c, x;
            cin >> c >> x;

            pair<int64_t, int64_t> p = make_pair(x, c);
            a.push_back(p);

        } else if (t == 2) {
            int64_t k;
            cin >> k;
            int64_t ans = 0;

            while (k > 0) {
                pair<int64_t, int64_t>& p = a.front();

                if (p.second > k) {
                    ans += p.first * k;
                    p.second -= k;
                    break;

                } else if (p.second == k) {
                    ans += p.first * k;
                    a.erase(a.begin());
                    break;
                } else {
                    ans += p.first * p.second;
                    k -= p.second;

                    a.pop_front();
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}
