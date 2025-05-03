#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate_table(const vector<vector<int>> &table) {
    int n = table.size();
    vector<vector<int>> rotated(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = table[i][j];
        }
    }

    return rotated;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> s(n, vector<int>(n)), t(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '.')
                s.at(i).at(j) = 0;
            else
                s.at(i).at(j) = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '.')
                t.at(i).at(j) = 0;
            else
                t.at(i).at(j) = 1;
        }
    }

    vector<vector<int>> s_rot_90 = rotate_table(s);
    vector<vector<int>> s_rot_180 = rotate_table(s_rot_90);
    vector<vector<int>> s_rot_270 = rotate_table(s_rot_180);

    int cnt = 0, cnt_90 = 0, cnt_180 = 0, cnt_270 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s.at(i).at(j) != t.at(i).at(j)) {
                cnt++;
            }
            if (s_rot_90.at(i).at(j) != t.at(i).at(j)) {
                cnt_90++;
            }
            if (s_rot_180.at(i).at(j) != t.at(i).at(j)) {
                cnt_180++;
            }
            if (s_rot_270.at(i).at(j) != t.at(i).at(j)) {
                cnt_270++;
            }
        }
    }

    cout << min({abs(cnt), abs(cnt_90) + 1, abs(cnt_180) + 2, abs(cnt_270) + 3})
         << endl;

    return 0;
}
