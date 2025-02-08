#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, a;
    cin >> n >> t >> a;

    if (abs(t - a) > (n - t - a)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
