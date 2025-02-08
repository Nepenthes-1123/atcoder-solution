#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> A(m), X;
    for (int i = 0; i < m; ++i) {
        cin >> A.at(i);
    }

    sort(A.begin(), A.end());

    int c = 0;

    for (int i = 0; i < n; ++i) {
        if (i - c < (int)A.size() && A.at(i - c) == i + 1) {
            continue;
        }

        X.push_back(i + 1);
        ++c;
    }

    cout << c << endl;

    for (int x : X) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
