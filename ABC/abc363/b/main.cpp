#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, P;
    cin >> N >> T >> P;

    vector<int> L(N);

    for (int i = 0; i < N; ++i) {
        cin >> L.at(i);
    }

    sort(L.begin(), L.end(), greater<int>{});

    cout << max(0, T - L.at(P - 1)) << endl;
}
