#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2 - 1; ++i) {
            cout << "-";
        }
        cout << "==";

        for (int i = 0; i < n / 2 - 1; ++i) {
            cout << "-";
        }

    } else {
        for (int i = 0; i < n / 2; ++i) {
            cout << "-";
        }
        cout << "=";

        for (int i = 0; i < n / 2; ++i) {
            cout << "-";
        }
    }

    cout << endl;

    return 0;
}
