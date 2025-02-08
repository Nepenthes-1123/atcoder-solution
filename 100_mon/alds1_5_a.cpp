#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int q;
        cin >> q;
        bool ok = false;
        for (int msk = 0; msk < (1 << N); ++msk) {
            int sm = 0;
            for (int j = 0; j < N; ++j) {
                if (msk & (1 << j)) sm += A.at(j);
            }
            if (q == sm) {
                cout << "yes" << endl;
                ok = true;
            }
        }
        if (!ok) cout << "no" << endl;
    }
}
