#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a;
    cin >> N;

    map<int, int> count;

    for (int i = 0; i < N; i++) {
        cin >> a;
        if (count.count(a)) {
            count.at(a)++;
        } else {
            count[a] = 1;
        }
    }

    int key, value = 0;

    for (auto p : count) {
        auto k = p.first;
        auto v = p.second;

        if (v > value) {
            key = k;
            value = v;
        }
    }

    cout << key << " " << value << endl;
}
