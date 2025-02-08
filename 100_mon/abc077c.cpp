#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);

    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; ++i) {
        cin >> B.at(i);
    }
    for (int i = 0; i < N; ++i) {
        cin >> C.at(i);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int64_t sum = 0;

    for (int b : B) {
        int64_t u = lower_bound(A.begin(), A.end(), b) - A.begin();
        int64_t l = C.end() - upper_bound(C.begin(), C.end(), b);
        sum += u * l;
    }

    cout << sum << endl;
}
