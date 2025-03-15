#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A.at(i);
    }

    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        set<int> L, R;
        for (int j = 0; j < n; ++j) {
            if (j <= i) {
                L.insert(A.at(j));
            } else {
                R.insert(A.at(j));
            }
        }

        ans = max(ans, (int)L.size() + (int)R.size());
    }

    cout << ans << endl;

    return 0;
}
