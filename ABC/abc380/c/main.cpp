#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> mass;
    char top = s.at(0);
    char pre = s.at(0);
    int count = 0;

    // 塊カウント
    for (char c : s) {
        if (pre == c) {
            ++count;
        } else {
            mass.push_back(count);
            pre = c;
            count = 1;
        }
    }
    mass.push_back(count);

    // 入れ替え
    if (top == '1') {
        int ones = mass.at((2 * k - 1) - 1);
        mass.at((2 * (k - 1) - 1) - 1) += ones;
        mass.at((2 * k - 1) - 1) = 0;
    } else {
        int ones = mass.at(2 * k - 1);
        mass.at(2 * (k - 1) - 1) += ones;
        mass.at(2 * k - 1) = 0;
    }

    pre = top == '1' ? '0' : '1';
    for (int c : mass) {
        if (pre == '1') {
            for (int i = 0; i < c; ++i) {
                cout << 0;
            }
        } else {
            for (int i = 0; i < c; ++i) {
                cout << 1;
            }
        }

        pre = pre == '1' ? '0' : '1';
    }
    cout << endl;

    return 0;
}
