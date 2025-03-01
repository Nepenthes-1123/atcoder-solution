#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, string>> S;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        S.push_back(make_pair((int)s.size(), s));
    }

    sort(S.begin(), S.end());

    for (auto c : S) {
        cout << c.second;
    }

    cout << endl;

    return 0;
}
