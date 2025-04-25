#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int64_t x = 0;

    for (int i = 0; i < m + 1; i++) {
        x += pow(n, i);
        if (x > 1e9) {
            cout << "inf" << endl;
            return 0;
        }
    }

    cout << x << endl;

    return 0;
}
