#include <bits/stdc++.h>
using namespace std;

class UnionFind {
   public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent.at(i) = i;
        }
    }

    int find(int x) {
        if (parent.at(x) != x) {
            parent.at(x) = find(parent.at(x));
        }
        return parent.at(x);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank.at(rootX) < rank.at(rootY)) {
                parent.at(rootX) = rootY;
            } else if (rank.at(rootX) > rank.at(rootY)) {
                parent.at(rootY) = rootX;
            } else {
                parent.at(rootY) = rootX;
                rank.at(rootX)++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> degree(n, 0);
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        degree.at(a)++;
        degree.at(b)++;
        edges.at(i) = {a, b};
    }

    if (n != m) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (degree.at(i) != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    UnionFind uf(n);

    for (int i = 1; i < m; ++i) {
        int a = edges.at(i).first;
        int b = edges.at(i).second;

        if (uf.find(a) == uf.find(b)) {
            cout << "No" << endl;
            return 0;
        }
        uf.unite(a, b);
    }

    cout << "Yes" << endl;
    return 0;
}
