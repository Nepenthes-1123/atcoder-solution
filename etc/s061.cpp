#include <bits/stdc++.h>
using namespace std;

using vec2di = vector<vector<int>>;

void bfs(int y, int x, int h, int w, int ori_y, int ori_x, vec2di &board,
         vec2di &dp, queue<pair<int, int>> &que, vec2di &visited,
         vec2di &count) {
    if (0 <= y && y < h && 0 <= x && x < w) {
        if (dp.at(ori_y).at(ori_x) + board.at(y).at(x) >= dp.at(y).at(x) &&
            !visited.at(y).at(x)) {
            // 近傍のdp = max(自身のdp + 近傍の値,近傍のdp)
            dp.at(y).at(x) = dp.at(ori_y).at(ori_x) + board.at(y).at(x);

            count.at(y).at(x) = count.at(ori_y).at(ori_x) + 1;
            // 更新した近傍をpush
            que.push(make_pair(y, x));
        }
    }
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    // 各層のコインの最大数を記録
    vector<int> max_coins(n);

    for (int k = 0; k < n; ++k) {
        // 階層の記録
        vec2di board(h, vector<int>(w));
        pair<int, int> s, g;

        //  階層中のコイン数のdp
        vec2di dp(h, vector<int>(w, 0));

        // 到達判定
        vec2di visited(h, vector<int>(w, 0));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char c;
                cin >> c;
                if (c == 'S') {
                    board.at(i).at(j) = 0;
                    s = make_pair(i, j);
                } else if (c == 'G') {
                    board.at(i).at(j) = 0;
                    g = make_pair(i, j);
                } else {
                    board.at(i).at(j) = int(c - '0');
                }
            }
        }

        // スタートから4近傍に対してabs(ゴール座標x-スタート座標x) +
        // abs(ゴール座標y-スタート座標y)回だけbfs
        // bfsの繰り返し数をカウント
        int count = abs(s.first - g.first) + abs(s.second - g.second);
        vec2di bfs_count(h, vector<int>(w, 0));

        queue<pair<int, int>> que;
        que.push(s);
        bfs_count.at(s.first).at(s.second) = 1;

        while (!que.empty()) {
            pair b = que.front();
            que.pop();
            // 超過探索を打ち切り
            if (bfs_count.at(b.first).at(b.second) > count) break;

            visited.at(b.first).at(b.second) = 1;

            bfs(b.first - 1, b.second, h, w, b.first, b.second, board, dp, que,
                visited, bfs_count);
            bfs(b.first, b.second - 1, h, w, b.first, b.second, board, dp, que,
                visited, bfs_count);
            bfs(b.first + 1, b.second, h, w, b.first, b.second, board, dp, que,
                visited, bfs_count);
            bfs(b.first, b.second + 1, h, w, b.first, b.second, board, dp, que,
                visited, bfs_count);
        }

        max_coins.at(k) = dp.at(g.first).at(g.second);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += max_coins.at(i);
    }

    cout << ans << endl;
}
