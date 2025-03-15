#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int pre_a = 0, a;

    for (int i = 0; i < n; ++i) {
        cin >> a;

        if (pre_a < a) {
            pre_a = a;

        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
