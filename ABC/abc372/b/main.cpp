#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> three_pows(11);
    vector<int> N;

    for (int i = 0; i < 11; ++i) {
        three_pows.at(i) = pow(3, i);
    }

    reverse(three_pows.begin(), three_pows.end());

    while (m > 0) {
        for (int i = 0; i < 11; ++i) {
            if (m >= three_pows.at(i)) {
                m -= three_pows.at(i);
                N.push_back(10 - i);
                break;
            }
        }
    }

    cout << N.size() << endl;

    for (int n : N) cout << n << " ";

    cout << endl;

    return 0;
}
