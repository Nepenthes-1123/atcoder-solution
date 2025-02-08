#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l = -1, r = -1, a, ans = 0;
    cin >> n;

    string s;

    for (int i = 0; i < n; ++i) {
        cin >> a >> s;
        if (s == "R") {
            if (r == -1) {
                r = a;
            } else {
                ans += abs(r - a);
                r = a;
            }
        } else if (s == "L") {
            if (l == -1) {
                l = a;
            } else {
                ans += abs(l - a);
                l = a;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
