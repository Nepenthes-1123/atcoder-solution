#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (N == (i + 1) * (j + 1)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
