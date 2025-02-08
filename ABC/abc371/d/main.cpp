#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;

    cin >> n;

    vector<int> x(n), p(n);

    for (int i = 0; i < n; ++i) {
        cin >> x.at(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> p.at(i);
    }

    cin >> q;

    vector<int> l(q), r(q);

    int L, R;

    for (int i = 0; i < q; ++i) {
        cin >> L >> R;
        l.at(i) = lower_bound(x.begin(), x.end(), L) - x.begin();
        r.at(i) = upper_bound(x.begin(), x.end(), R) - x.begin();
    }

    vector<int64_t> sum(n + 1, 0);
    int j;
    for (int i = 0; i < n; ++i) {
        j = i + 1;
        sum.at(j) = p.at(i) + sum.at(j - 1);
    }

    for (int i = 0; i < q; ++i) {
        cout << sum.at(r.at(i)) - sum.at(l.at(i)) << endl;
        // cout << r.at(i) << " ; " << l.at(i) << endl;
    }

    return 0;
}
