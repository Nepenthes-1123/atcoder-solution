#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    bool pre_sweet = false;
    for (int i = 0; i < N; ++i) {
        cin >> S.at(i);
    }

    for (int i = 0; i < N; ++i) {
        if (pre_sweet) {
            if (S.at(i) == "sweet" && i != N - 1) {
                cout << "No" << endl;
                return 0;
            } else {
                pre_sweet = false;
            }
        } else {
            if (S.at(i) == "sweet") {
                pre_sweet = true;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
