#include <bits/stdc++.h>

using namespace std;

bool f(int x, vector<int> a, int b, int k) {
    auto lb = lower_bound(a.begin(), a.end(), b - x);
    auto ub = upper_bound(a.begin(), a.end(), b + x);
    return ub - lb >= k;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    while (q--) {
        int b, k;
        cin >> b >> k;

        int ng = -1, ok = (int)2e8 + 10;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (f(mid, a, b, k))
                ok = mid;
            else
                ng = mid;
        }
        cout << ok << '\n';
    }
}
