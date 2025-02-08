#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int quo = 1000000;

    for (int i = 0; i < N; i++) {
        int A, count = 0;
        cin >> A;

        while (A % 2 == 0) {
            count++;
            A /= 2;
        }

        if (quo > count) {
            quo = count;
        }
    }

    cout << quo << endl;
}
