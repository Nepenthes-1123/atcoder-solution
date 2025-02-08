#include <bits/stdc++.h>
using namespace std;

class Edge {
   public:
    int a, b, w;

    Edge();
    Edge(int, int, int);
    ~Edge();
};

Edge::Edge() {}
Edge::Edge(int u, int v, int weight) {
    a = u;
    b = v;
    w = weight;
}

Edge::~Edge() {}

class UnionFind {
   private:
    vector<int> p;
    vector<int> r;

   public:
    UnionFind();
    UnionFind(int);
    ~UnionFind();

    int find(int);

    void unite(int, int);

    bool is_connected(int, int);
};

UnionFind::UnionFind() {}
UnionFind::UnionFind(int size) {
    p.resize(size);
    r.resize(size);
    for (int i = 0; i < size; ++i) {
        p.at(i) = i;
    }
}

UnionFind::~UnionFind() {}

int UnionFind::find(int x) {
    if (p.at(x) != x) {
        p.at(x) = find(p.at(x));
    }
    return p.at(x);
}

void UnionFind::unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx != ry) {
        if (r.at(rx) < r.at(ry)) {
            p.at(rx) = ry;
        } else if (r.at(rx) > r.at(ry)) {
            p.at(ry) = rx;
        } else {
            p.at(ry) = rx;
            ++r.at(rx);
        }
    }
}

bool UnionFind::is_connected(int x, int y) { return find(x) == find(y); }

bool all_connected(int index, int n, vector<int> &a, vector<Edge> &edges) {
    UnionFind uf(n);

    for (Edge &edge : edges) {
        if (edge.w < a.at(index)) {
            uf.unite(edge.a, edge.b);
        }
    }

    bool isConnected = true;

    for (int i = 1; i < n; ++i) {
        if (!uf.is_connected(0, i)) {
            isConnected = false;
            break;
        }
    }

    return isConnected;
}

int binary_search(int n, vector<int> &a, vector<Edge> &edges) {
    int ng = -1;
    int ok = (int)a.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (all_connected(mid, n, a, edges)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<int> costs(m);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;

        edges.at(i) = Edge(a, b, c);
        costs.at(i) = c;
    }

    sort(costs.begin(), costs.end());

    int lim_cost_index = binary_search(n, costs, edges);

    if (lim_cost_index < (int)costs.size()) {
        cout << costs.at(binary_search(n, costs, edges)) << endl;
    } else {
        cout << *max_element(costs.begin(), costs.end()) + 1 << endl;
    }
}
