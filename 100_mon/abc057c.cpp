#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    int min_dig = 11;
    cin >> N;
    int64_t a;

    for (int64_t i = 0; i * i < N; ++i) {
        a = i + 1;
        if (N % a == 0) {
            min_dig = min(min_dig, (int)max(to_string(a).length(),
                                            to_string(N / a).length()));
        }
    }

    cout << min_dig << endl;
}
