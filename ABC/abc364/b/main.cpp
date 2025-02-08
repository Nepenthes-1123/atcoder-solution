#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, S_i, S_j;
    cin >> H >> W >> S_i >> S_j;

    --S_i;
    --S_j;

    vector<vector<char>> C(H, vector<char>(W));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> C.at(i).at(j);
        }
    }

    string X;
    cin >> X;

    for (char x : X) {
        if (x == 'L') {
            // S_i,S_j-1を判定
            if (S_j - 1 >= 0 && C.at(S_i).at(S_j - 1) == '.') {
                --S_j;
            }
        } else if (x == 'R') {
            // S_i,S_j+1を判定
            if (S_j + 1 < W && C.at(S_i).at(S_j + 1) == '.') {
                ++S_j;
            }
        } else if (x == 'U') {
            // S_i-1,S_jを判定
            if (S_i - 1 >= 0 && C.at(S_i - 1).at(S_j) == '.') {
                --S_i;
            }
        } else if (x == 'D') {
            // S_i+1,S_jを判定
            if (S_i + 1 < H && C.at(S_i + 1).at(S_j) == '.') {
                ++S_i;
            }
        }
    }

    cout << ++S_i << " " << ++S_j << endl;

    return 0;
}
