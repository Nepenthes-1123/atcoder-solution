#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> first_num;
    int interval = 200000;

    int a;

    for (int i = 0; i < n; ++i) {
        cin >> a;

        if (first_num.count(a)) {
            interval = min(interval, i - first_num.at(a));
        } else {
            first_num[a] = i;
        }
    }

    if (interval != 200000) {
        cout << interval + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
