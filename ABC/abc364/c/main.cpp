#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, X, Y;

    cin >> N >> X >> Y;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; ++i) {
        cin >> B.at(i);
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int64_t cnt_A = 0, cnt_B = 0;

    int64_t sum = 0;
    for (int a : A) {
        sum += a;
        ++cnt_A;
        if (sum > X) break;
    }

    sum = 0;
    for (int b : B) {
        sum += b;
        ++cnt_B;
        if (sum > Y) break;
    }

    cout << min(cnt_A, cnt_B) << endl;
    return 0;
}
