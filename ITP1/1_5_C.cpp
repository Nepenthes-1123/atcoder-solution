#include <bits/stdc++.h>
using namespace std;

void print_chess(int num) {
    if (num % 2 == 0) {
        cout << "#";
    } else {
        cout << ".";
    }
}

int main() {
    int H, W;
    while (cin >> H >> W) {
        if (H == 0 && W == 0) return 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                print_chess(i + j);
            }
            cout << endl;
        }
        cout << endl;
    }
}
