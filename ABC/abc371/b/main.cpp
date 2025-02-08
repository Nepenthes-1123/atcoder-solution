#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> check(n, 0);

    vector<int> a(m);
    vector<string> b(m);

    for (int i = 0; i < m; ++i) {
        cin >> a.at(i) >> b.at(i);
        --a.at(i);
    }

    int ai;
    string bi;

    for (int i = 0; i < m; ++i) {
        ai = a.at(i);
        bi = b.at(i);

        if (bi == "M" && check.at(ai) == 0) {
            cout << "Yes" << endl;
            check.at(ai) = 1;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
