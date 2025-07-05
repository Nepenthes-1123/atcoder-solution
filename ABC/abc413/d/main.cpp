#include <bits/stdc++.h>
using namespace std;

struct AbsCompare {
    bool operator()(int64_t a, int64_t b) const { return abs(a) > abs(b); }
};

int main() {
    int outer_t;
    cin >> outer_t;

    for (int outer_i = 0; outer_i < outer_t; ++outer_i) {
        int n;
        cin >> n;

        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a.at(i);
        }
        sort(a.begin(), a.end(), AbsCompare());  // 絶対値降順にソート

        bool flag = true;

        for (int i = 2; i < n; ++i) {
            if (a.at(i - 1) * a.at(1) != a.at(i) * a.at(0)) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
