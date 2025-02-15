#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;

    map<int, set<int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        if (u == v) {
            ++count;
            continue;
        }

        int min_v = min(u, v), max_v = max(u, v);

        if (edges.count(min_v)) {
            if (edges.at(min_v).find(max_v) == edges.at(min_v).end()) {
                edges.at(min_v).insert(max_v);
            } else {
                ++count;
            }
        } else {
            set<int> s = {max_v};
            edges[min_v] = s;
        }
    }

    cout << count << endl;

    return 0;
}
