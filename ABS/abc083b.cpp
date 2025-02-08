#include <bits/stdc++.h>
using namespace std;

int digits_sum(int N) {
    int sum = 0;

    while (N > 0) {
        sum += N % 10;
        N /= 10;
    }

    return sum;
}

int main() {
    int N, A, B, dig_sum, sum = 0;
    cin >> N >> A >> B;

    for (int i = 1; i < N + 1; i++) {
        dig_sum = digits_sum(i);
        if (dig_sum >= A && dig_sum <= B) {
            sum += i;
        }
    }

    cout << sum << endl;
}
