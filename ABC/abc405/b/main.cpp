#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> exis_num;

    for (int i = 0; i < n; ++i) {
        bool ok = true;
        int a;

        cin >> a;
        exis_num.insert(a);

        for (int j = 0; j < m; ++j) {
            if (exis_num.count(j + 1))
                continue;
            else
                ok = false;
        }

        if (ok) {
            cout << n - i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
