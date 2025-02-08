#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = -1, X = -1;

    while (N != 0 || X != 0) {
        int count = 0;
        cin >> N >> X;

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int c = N - i - j;
                if (j < c && c < N) {
                    ++count;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
