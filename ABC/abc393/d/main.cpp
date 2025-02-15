#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    int c1 = 0;
    for (char c : s) {
        if (c == '1') ++c1;
    }

    int now = 0;
    int64_t ans = 0;

    for (char c : s) {
        if (c == '0') {
            ans += min(now, c1 - now);
        } else {
            ++now;
        }
    }

    cout << ans << endl;

    return 0;
}
