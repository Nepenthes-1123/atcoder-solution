#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int n_500 = min(A, X / 500);
    int x_rem_i, x_rem_j;

    int count = 0;

    for (int i = 0; i <= n_500; i++) {
        x_rem_i = X - 500 * i;
        int n_100 = min(B, x_rem_i / 100);
        for (int j = 0; j <= n_100; j++) {
            x_rem_j = x_rem_i - 100 * j;
            if (x_rem_j % 50 == 0 && x_rem_j / 50 <= C && x_rem_j >= 0) {
                count++;
            }
        }
    }

    cout << count << endl;
}
