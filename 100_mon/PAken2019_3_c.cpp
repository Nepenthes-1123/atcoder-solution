#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int64_t>> A(N, vector<int64_t>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A.at(i).at(j);
        }
    }

    int64_t high_score = 0;
    for (int j1 = 0; j1 < M; ++j1) {
        for (int j2 = j1 + 1; j2 < M; ++j2) {
            int64_t sm = 0;
            for (int i = 0; i < N; ++i) {
                sm += max(A.at(i).at(j1), A.at(i).at(j2));
            }
            high_score = max(high_score, sm);
        }
    }

    cout << high_score << endl;
}
