#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        if ((i + ans) % 2 == 0 && s.at(i) != 'i') {
            ++ans;
        } else if ((i + ans) % 2 == 1 && s.at(i) != 'o') {
            ++ans;
        }
    }

    if (((int)s.size() + ans) % 2 == 1) ++ans;

    cout << ans << endl;

    return 0;
}
