#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int AB = max(X, Y);

    int64_t price = 10000000000;

    for (int i = 0; i <= AB; ++i) {
        price = min(price, (int64_t)(A * max(0, X - i) + B * max(0, Y - i) +
                                     C * 2 * i));
    }

    cout << price << endl;
}
