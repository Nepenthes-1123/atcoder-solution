#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;

    cin >> n >> k >> s;

    int cnt = 0, ans = 0;

    for (char c : s) {
        if (c == 'O') {
            ++cnt;
        } else if (c == 'X') {
            cnt = 0;
        }

        if (cnt == k) {
            ++ans;
            cnt = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
