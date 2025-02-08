#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a.at(i);
    }

    int cnt = 0;
    while (true) {
        sort(a.rbegin(), a.rend());
        if (a.at(0) <= 0 || a.at(1) <= 0) break;
        --a.at(0);
        --a.at(1);
        ++cnt;
    }

    cout << cnt << endl;
    return 0;
}
