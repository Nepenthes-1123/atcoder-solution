#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N), Q(N), ord(N);

    for (int i = 0; i < N; ++i) {
        cin >> P.at(i);
    }

    for (int i = 0; i < N; ++i) {
        cin >> Q.at(i);
        ord.at(i) = i + 1;
    }

    int num = 0, ord_p, ord_q;
    do {
        bool eq_p = true, eq_q = true;
        for (int i = 0; i < N; ++i) {
            if (P.at(i) != ord.at(i)) {
                eq_p = false;
            }
            if (Q.at(i) != ord.at(i)) {
                eq_q = false;
            }
        }
        if (eq_p) ord_p = num;
        if (eq_q) ord_q = num;

        ++num;

    } while (next_permutation(ord.begin(), ord.end()));

    cout << abs(ord_p - ord_q) << endl;
}
