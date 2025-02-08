#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> P(n), Q(n);
    for (int i = 0; i < n; ++i) {
        cin >> P.at(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> Q.at(i);
    }

    vector<int> best(n);

    for (int i = 0; i < n; ++i) {
        best.at(i) = Q.at(P.at(i) - 1);
    }

    map<int, int> Q_best;

    for (int i = 0; i < n; ++i) {
        Q_best[Q.at(i)] = best.at(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << Q_best.at(i + 1) << " ";
    }
    cout << endl;

    return 0;
}
