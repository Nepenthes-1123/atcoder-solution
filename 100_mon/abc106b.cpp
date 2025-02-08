#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, count, ans = 0;
    cin >> N;

    for (int i = 0; i < N; i += 2) {
        count = 0;
        for (int j = 0; j < i + 1; j++) {
            if ((i + 1) % (j + 1) == 0) {
                ++count;
            }
        }
        if (count == 8) {
            ++ans;
        }
    }

    cout << ans << endl;
}
