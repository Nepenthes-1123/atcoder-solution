#include <bits/stdc++.h>
using namespace std;

struct ant {
    int dir;
    double pos;
};

int main() {
    int N, T;  // 蟻の数N,制限時間T
    string S;  // 蟻の向きをビット列で表した文字列

    cin >> N >> T >> S;

    vector<ant> ants(N);  // 蟻ID,ant(向き,現在位置)
    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        ant ant = {(int)(S.at(i) - '0'), x};
        ants.at(i) = ant;
    }

    vector<ant> fut_ants = ants;  // 単位時間経過後の蟻の位置を保存

    for (int i = 0; i < N; i++) {
        if (ants.at(i).dir) {
            fut_ants.at(i).pos += T + 0.1;
        } else {
            fut_ants.at(i).pos -= T + 0.1;
        }
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (ants.at(i).dir != ants.at(j).dir &&
                (ants.at(i).pos < ants.at(j).pos) !=
                    (fut_ants.at(i).pos < fut_ants.at(j).pos)) {
                count++;
            }
        }
    }

    cout << count << endl;
}
