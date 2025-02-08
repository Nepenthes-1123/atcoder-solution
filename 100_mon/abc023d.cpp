#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> H(N), S(N);

    for (int i = 0; i < N; ++i) {
        cin >> H.at(i) >> S.at(i);
    }

    vector<int64_t> pen(N);

    for (int i = 0; i < N; ++i) {
        pen.at(i) = H.at(i) + (N - 1) * S.at(i);
    }

    sort(pen.begin(), pen.end());
}
