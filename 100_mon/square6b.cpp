#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int64_t sm_time = 0;
    vector<int64_t> A(N), B(N);

    for (int i = 0; i < N; ++i) {
        int64_t a, b;
        cin >> a >> b;
        sm_time += b - a;
        A.at(i) = a;
        B.at(i) = b;
    }

    // int64_t A_min, A_max, B_min, B_max;

    // A_min = *min_element(A.begin(), A.end());
    // A_max = *max_element(A.begin(), A.end());
    // B_min = *min_element(B.begin(), B.end());
    // B_max = *max_element(B.begin(), B.end());

    int64_t sm_time_a = 100000000000;
    for (int64_t i : A) {
        int64_t time_a_asm = 0;
        for (int64_t a : A) {
            time_a_asm += abs(a - i);
        }
        sm_time_a = min(sm_time_a, time_a_asm);
    }

    int64_t sm_time_b = 100000000000;
    for (int64_t i : B) {
        int64_t time_b_asm = 0;
        for (int64_t b : B) {
            time_b_asm += abs(b - i);
        }
        sm_time_b = min(sm_time_b, time_b_asm);
    }

    cout << sm_time + sm_time_a + sm_time_b << endl;
}
