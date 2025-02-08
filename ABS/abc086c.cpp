#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    tuple<int, int, int> pre_pos(0, 0, 0), pos;

    bool can = true;

    for (int i = 0; i < N; ++i) {
        int t, x, y, dist, interval;
        cin >> t >> x >> y;
        pos = make_tuple(t, x, y);

        dist = abs(get<1>(pre_pos) - x) + abs(get<2>(pre_pos) - y);

        interval = t - get<0>(pre_pos);

        if (dist > interval || (dist - interval) % 2 != 0) {
            can = false;
        }

        pre_pos = pos;
    }

    if (can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
