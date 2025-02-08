#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> tree(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;

        tree.at(i).first = min(a, b);
        tree.at(i).second = max(a, b);
    }

    vector<int> v(k);
    for (int i = 0; i < k; ++i) {
        cin >> v.at(i);
    }

    vector<int> target;

    for (int a : v) {
        if (a == 1) {
            target.push_back(a);
        } else {
        }
    }

    return 0;
}
