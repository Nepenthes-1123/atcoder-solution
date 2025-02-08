#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n)));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> a.at(i).at(j).at(k);
            }
        }
    }

    int now = 0, pre = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                now = a.at(i).at(j).at(k);
                a.at(i).at(j).at(k) += pre;
                pre = now;
            }
        }
    }

    int q;
    cin >> q;
    vector<vector<int>> query(q, vector<int>(6));

    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> query.at(i).at(j);
            --query.at(i).at(j);
        }
    }

    for (int Q = 0; Q < q; ++Q) {
        int sum = 0;
        for (int i = query.at(Q).at(0); i <= query.at(Q).at(1); ++i) {
            for (int j = query.at(Q).at(2); j <= query.at(Q).at(3); ++j) {
                // for (int k = query.at(Q).at(4); k <= query.at(Q).at(5); ++k)
                // {
                //     sum += a.at(i).at(j).at(k);
                // }

                if (query.at(Q).at(4) - 1 < 0) {
                    sum += a.at(i).at(j).at(query.at(Q).at(5));
                } else {
                    sum += a.at(i).at(j).at(query.at(Q).at(5)) -
                           a.at(i).at(j).at(query.at(Q).at(4) - 1);
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}
