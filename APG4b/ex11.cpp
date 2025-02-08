#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 0, A = 0, B = 0;
    cin >> N >> A;

    string op;

    // ここにプログラムを追記
    for (int i = 0; i < N; i++) {
        cin >> op >> B;

        if (op == "+") {
            A += B;
        } else if (op == "-") {
            A -= B;
        } else if (op == "*") {
            A *= B;
        } else if (op == "/" && B != 0) {
            A /= B;
        } else {
            cout << "error" << endl;
            break;
        }

        cout << i + 1 << ":" << A << endl;
    }
}
