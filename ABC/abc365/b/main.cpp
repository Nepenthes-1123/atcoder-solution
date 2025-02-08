#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }

    int f = 0, s = 0;
    if (A.at(0) > A.at(1)) {
        f = 0;
        s = 1;
    } else {
        f = 1;
        s = 0;
    }

    for (int i = 2; i < N; ++i) {
        if (A.at(i) > A.at(f)) {
            s = f;
            f = i;
        } else if (A.at(i) > A.at(s)) {
            s = i;
        }
    }

    cout << s + 1 << endl;

    return 0;
}
