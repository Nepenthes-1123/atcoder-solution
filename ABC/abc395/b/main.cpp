#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<char>> boards(n, vector<char>(n, '#'));

    for (int i = 0; i < n; ++i) {
        int j = n - i;
        if (i <= j) {
            char fill;
            if (i % 2 != 1) {
                fill = '#';
            } else {
                fill = '.';
            }

            for (int k = i; k < j; ++k) {
                for (int l = i; l < j; ++l) {
                    boards.at(k).at(l) = fill;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << boards.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}
