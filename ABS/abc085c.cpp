#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            int z = N - (i + j);
            if (0 <= z) {
                if (10000 * i + 5000 * j + 1000 * z == Y) {
                    cout << i << " " << j << " " << z << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 1;
}
