#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H, x, y, r;
    cin >> W >> H >> x >> y >> r;
    if (r <= x && r <= y && x <= W - r && y <= H - r) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
