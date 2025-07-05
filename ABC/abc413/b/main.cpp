#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s.at(i);
    }

    set<string> ans;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) ans.insert(s.at(i) + s.at(j));
        }
    }

    cout << ans.size() << endl;

    return 0;
}
