#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;

    cin >> N >> Q;

    vector<int64_t> A(N), B(Q), K(Q);

    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < Q; ++i) {
        cin >> B.at(i) >> K.at(i);
    }

    for (int i = 0; i < Q; ++i) {
        int64_t b = B.at(i), k = K.at(i);
        vector<int64_t> D(2 * k, numeric_limits<int>::max());

        int index = lower_bound(A.begin(), A.end(), b) - A.begin();

        int s_indx = max((int64_t)0, index - k);
        int e_indx = min((int64_t)N, index + k);

        copy(A.begin() + s_indx, A.begin() + e_indx, D.begin());

        for (int i = 0; i < 2 * k; ++i) {
            D.at(i) = abs(D.at(i) - b);
        }

        sort(D.begin(), D.end());

        // for (int64_t d : D) {
        //     cout << d << " ";
        // }
        // cout << endl;

        cout << D.at(k - 1) << endl;
    }

    return 0;
}
