#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int64_t M;

    cin >> N >> M;

    vector<int> A(N);
    int64_t sum = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
        sum += A.at(i);
    }

    if (sum <= M) {
        cout << "infinite" << endl;
    } else {
        sort(A.begin(), A.end());
        // 交通費補助額の上限額xを二分探索で求める
        int left = 0, right = *max_element(A.begin(), A.end());
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            int64_t sum2 = 0;
            for (int i = 0; i < N; ++i) {
                sum2 += min(A.at(i), mid);
            }
            if (sum2 > M) {
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << left << " " << right << endl;
    }

    return 0;
}
