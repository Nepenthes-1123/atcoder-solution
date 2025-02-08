// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     vector<vector<int>> honests(N);
//     vector<vector<int>> liars(N);

//     for (int i = 0; i < N; ++i) {
//         int A;
//         cin >> A;
//         for (int j = 0; j < A; ++j) {
//             int x, y;
//             cin >> x >> y;
//             if (y == 0)
//                 liars.at(i).push_back(--x);
//             else
//                 honests.at(i).push_back(--x);
//         }
//     }

//     int ans = 0;
//     for (int msk = 0; msk < (1 << N); ++msk) {
//         bool ok = true;
//         int tot = 0;
//         for (int i = 0; i < N; ++i) {
//             if (msk & (1 << i)) {
//                 ++tot;
//                 for (int honests : honests.at(i)) {
//                     if (!(msk & (1 << honests))) {
//                         ok = false;
//                     }
//                 }
//                 for (int liar : liars.at(i)) {
//                     if (msk & (1 << liar)) {
//                         ok = false;
//                     }
//                 }
//             }
//         }
//         if (ok) {
//             ans = max(ans, tot);
//         }
//     }

//     cout << ans << endl;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> testimonys(N);

    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        for (int j = 0; j < A; ++j) {
            int x, y;
            cin >> x >> y;
            testimonys.at(i).push_back(make_pair(--x, y));
        }
    }

    int ans = 0;
    for (int msk = 0; msk < (1 << N); ++msk) {
        bool ok = true;
        int tot = 0;
        for (int i = 0; i < N; ++i) {
            if (msk & (1 << i)) {
                ++tot;
                for (pair<int, int> testimony : testimonys.at(i)) {
                    if (testimony.second) {
                        if (!(msk & (1 << testimony.first))) ok = false;
                    } else {
                        if (msk & (1 << testimony.first)) ok = false;
                    }
                }
            }
        }
        if (ok) ans = max(ans, tot);
    }
    cout << ans << endl;
}
