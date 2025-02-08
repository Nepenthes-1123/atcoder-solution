#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<string> div = {"dream", "dreamer", "erase", "eraser"};

    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; ++i) reverse(div.at(i).begin(), div.at(i).end());

    for (int i = 0; i < (int)S.size();) {
        bool can = false;
        for (int j = 0; j < 4; ++j) {
            string d = div.at(j);
            if (S.substr(i, d.size()) == d) {
                // 切り分け可能
                can = true;
                i += d.size();
                break;
            }
        }
        if (!can) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
