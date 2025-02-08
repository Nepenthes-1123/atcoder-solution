#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> S(M);  // 電球が対応するスイッチを格納
    vector<int> P(M);          // 点灯条件を格納

    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int s;
            cin >> s;
            S.at(i).push_back(--s);
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> P.at(i);
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); ++i) {
        int ligt_up = 0;
        for (int j = 0; j < M; ++j) {
            int cnt = 0;
            for (auto s : S.at(j)) {
                if (i & (1 << s)) {
                    ++cnt;
                }
            }
            if (cnt % 2 == P.at(j)) {
                ++ligt_up;
            }
        }
        if (ligt_up == M) ++ans;
    }

    cout << ans << endl;
}
