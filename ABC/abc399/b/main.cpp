#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> P(n);

    for (int i = 0; i < n; ++i) {
        cin >> P.at(i);
    }

    vector<int> P_c(n);
    copy(P.begin(), P.end(), P_c.begin());

    sort(P.rbegin(), P.rend());

    int r = 1;
    map<int, int> cor_table;

    for (int i = 0; i < n; ++i) {
        int max = P.at(i);

        if (!cor_table.count(max)) {
            int k = count(P.begin(), P.end(), max);
            cor_table[max] = r;
            r += k;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << cor_table.at(P_c.at(i)) << endl;
    }

    return 0;
}
