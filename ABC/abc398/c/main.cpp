#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    map<int, int> cnt;

    for (int i = 0; i < n; ++i) {
        cin >> A.at(i);

        if (!cnt.count(A.at(i))) {
            cnt[A.at(i)] = 1;
        } else {
            cnt.at(A.at(i))++;
        }
    }

    int max_num = -1;

    for (auto i = cnt.begin(); i != cnt.end(); i++) {
        if (i->second == 1) {
            max_num = i->first;
        }
    }

    if (max_num == -1) {
        cout << max_num << endl;
    } else {
        cout << find(A.begin(), A.end(), max_num) - A.begin() + 1 << endl;
    }

    return 0;
}
