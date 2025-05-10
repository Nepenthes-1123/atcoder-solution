#include <bits/stdc++.h>
using namespace std;

struct coordinate {
    int h, w;
    coordinate(int h, int w) : h(h), w(w) {}
};

struct escape_cord {
    coordinate c;
    int id;

    escape_cord(coordinate c, int id) : c(c), id(id) {}
};

vector<int> dh = {1, 0, -1, 0}, dw = {0, 1, 0, -1};

void bfs(vector<escape_cord> es, int h, int w, vector<vector<char>> &b,
         vector<vector<int>> &d, vector<vector<int>> &ids) {
    queue<escape_cord> que;
    for (int i = 0; i < (int)es.size(); ++i) {
        escape_cord e = es[i];

        d[e.c.h][e.c.w] = 0;
        ids[e.c.h][e.c.w] = e.id;
        que.push(e);
    }

    while (!que.empty()) {
        escape_cord n = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
            coordinate s(n.c.h + dh[i], n.c.w + dw[i]);
            if (s.h < 0 || s.h >= h || s.w < 0 || s.w >= w) continue;

            if (b[s.h][s.w] != '.') continue;
            if (d[s.h][s.w] != -1) continue;

            d[s.h][s.w] = d[n.c.h][n.c.w] + 1;
            ids[s.h][s.w] = n.id;
            que.push(escape_cord(s, n.id));
        }
    }
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> board(h, vector<char>(w));  // 映画館の状況
    vector<escape_cord> escapes;                     // 非常口の座標と番号

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'E')
                escapes.push_back(
                    escape_cord(coordinate(i, j), escapes.size()));
        }
    }

    // 各マスの非常口までの距離（初期値-1）
    vector<vector<int>> escape_dist(h, vector<int>(w, -1));

    // 各マスの最近傍非常口ID
    vector<vector<int>> escape_id(h, vector<int>(w, -1));

    bfs(escapes, h, w, board, escape_dist, escape_id);

    vector<vector<char>> ans(h, vector<char>(w, '?'));

    vector<char> dir = {'v', '>', '^', '<'};
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (board[i][j] != '.') {
                ans[i][j] = board[i][j];
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                coordinate s(i + dh[k], j + dw[k]);
                if (s.h < 0 || s.h >= h || s.w < 0 || s.w >= w) continue;

                if (escape_dist[i][j] - 1 == escape_dist[s.h][s.w] &&
                    escape_id[i][j] == escape_id[s.h][s.w]) {
                    ans[i][j] = dir[k];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
