#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    string s;
    cin >> s;

    map<pair<int, int>, bool> boards;
    boards[make_pair(n, n)] = true;

    // 煙を発生させながら焚火と高橋君が移動すると考える
    // 焚火は最初(n,n)、高橋君は最初(n+r,n+c)に存在する
    // 時間に対応する差分値(x_t,y_t)だけ焚火と高橋君が移動しているとする

    int x = 0, y = 0;  // 差分値
    string ans = "";

    for (int i = 0; i < n; ++i) {
        char ch = s.at(i);
        if (ch == 'N') ++x;
        if (ch == 'S') --x;
        if (ch == 'W') ++y;
        if (ch == 'E') --y;
        // 差分値の更新

        boards[make_pair(n + y, n + x)] = true;
        // cout << "n+y=" << n + y << " n+x=" << n + x << endl;
        // cout << "n+c+y=" << n + c + y << " n+r+x=" << n + r + x << endl;
        if (n + y + c < 0 || n + x + r < 0 || n + y + c > 2 * n ||
            n + x + r > 2 * n) {
            ans += "0";
        } else {
            if (boards.count(make_pair(n + y + c, n + x + r)) &&
                boards.at(make_pair(n + y + c, n + x + r))) {
                ans += '1';
            } else {
                ans += '0';
            }
        }
    }

    cout << ans << endl;
    // cout << n + c << " " << n + r << endl;

    return 0;
}
