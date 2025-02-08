#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    while (cin >> H >> W && H != 0 && W != 0) {
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }
}
