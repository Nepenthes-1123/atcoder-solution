#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int64_t sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a.at(i);
        sum += a.at(i);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (sum - a.at(i)) * a.at(i);
    }

    cout << ans / 2 << endl;

    return 0;
}
