#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj_mtr(N, vector<int>(N, 0));

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        adj_mtr.at(--a).at(--b) = 1;
        adj_mtr.at(b).at(a) = 1;
    }

    vector<int> ord(N);
    for (int i = 0; i < N; ++i) {
        ord.at(i) = i;
    }

    int cnt = 0;
    do {
        bool can = true;
        for (int i = 0; i < N - 1; ++i) {
            if (!(adj_mtr.at(ord.at(i)).at(ord.at(i + 1)))) {
                can = false;
            }
        }
        if (can) ++cnt;
    } while (next_permutation(ord.begin() + 1, ord.end()));

    cout << cnt << endl;
}
