#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    map<int, set<int>> row, col;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        row[x].insert(y);
        col[y].insert(x);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            int s = row[b].size();
            cout << s << endl;
            for (int y : row[b]) {
                col[y].erase(b);
            }
            row[b].clear();

        } else if (a == 2) {
            int s = col[b].size();
            cout << s << endl;
            for (int x : col[b]) {
                row[x].erase(b);
            }
            col[b].clear();
        }
    }

    return 0;
}
