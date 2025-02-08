#include <bits/stdc++.h>
using namespace std;

int facctorialMethod(int k) {
    int sum = 1;
    for (int i = 1; i <= k; ++i) {
        sum *= i;
    }
    return sum;
}

int main() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    sort(S.begin(), S.end());

    int cnt = 0;

    do {
        bool ok = true;
        for (int i = 0; i < N - K + 1; ++i) {
            string s = S.substr(i, K);
            if (s == string(s.rbegin(), s.rend())) {
                ok = false;
            }
        }
        if (ok) ++cnt;
    } while (next_permutation(S.begin(), S.end()));

    cout << cnt << endl;
}
