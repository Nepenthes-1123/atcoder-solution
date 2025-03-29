#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> ans(t);

    for (int l = 0; l < t; ++l) {
        int n;
        cin >> n;

        int cnt = 0;

        map<int, pair<pair<int, int>, pair<int, int>>> next_to;

        vector<bool> rem_id(n, false);

        vector<int> A(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            cin >> A.at(i);
            --A.at(i);
        }

        for (int i = 0; i < 2 * n; ++i) {
            if (!next_to.count(A.at(i))) {
                if (i == 0) {
                    next_to[A.at(i)].first = make_pair(-1, A.at(i + 1));
                    if (A.at(i) == A.at(i + 1)) rem_id.at(A.at(i)) = true;
                } else if (i == 2 * n - 1) {
                    next_to[A.at(i)].first = make_pair(A.at(i - 1), -2);
                    if (A.at(i) == A.at(i - 1)) rem_id.at(A.at(i)) = true;
                } else {
                    next_to[A.at(i)].first =
                        make_pair(A.at(i - 1), A.at(i + 1));
                    if (A.at(i) == A.at(i - 1) || A.at(i) == A.at(i + 1))
                        rem_id.at(A.at(i)) = true;
                }
            } else {
                if (i == 0) {
                    next_to[A.at(i)].second = make_pair(-1, A.at(i + 1));
                } else if (i == 2 * n - 1) {
                    next_to[A.at(i)].second = make_pair(A.at(i - 1), -2);
                } else {
                    next_to[A.at(i)].second =
                        make_pair(A.at(i - 1), A.at(i + 1));
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (rem_id.at(i)) continue;
            if (next_to.at(i).first.first == next_to.at(i).second.first &&
                !rem_id.at(next_to.at(i).first.first)) {
                ++cnt;
            }
            if (next_to.at(i).first.first == next_to.at(i).second.second &&
                !rem_id.at(next_to.at(i).first.first)) {
                ++cnt;
            }
            if (next_to.at(i).first.second == next_to.at(i).second.first &&
                !rem_id.at(next_to.at(i).first.second)) {
                ++cnt;
            }
            if (next_to.at(i).first.second == next_to.at(i).second.second &&
                !rem_id.at(next_to.at(i).first.second)) {
                ++cnt;
            }
        }

        ans.at(l) = cnt;
    }

    for (int i = 0; i < t; ++i) {
        cout << ans.at(i) / 2 << endl;
    }

    return 0;
}
