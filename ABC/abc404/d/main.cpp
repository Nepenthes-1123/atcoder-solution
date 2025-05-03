#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> c(n);  // コスト、動物園ID
    for (int i = 0; i < n; ++i) {
        cin >> c.at(i).first;
        c.at(i).second = i;
    }

    vector<int> want_look_animals(m, 2);
    vector<pair<int, int>> count_animals(m);  // 国に存在する動物の数、動物ID

    for (int i = 0; i < m; ++i) {
        count_animals.at(i).second = i;
    }

    vector<vector<int>> zoo(n, vector<int>(m, 0));
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            --a;
            zoo.at(a).at(i) = 1;
        }
        count_animals.at(i).first = k;
    }

    sort(count_animals.begin(), count_animals.end());

    int64_t ans = 0;
    for (auto animal : count_animals) {
        if (want_look_animals.at(animal.second) == 0) continue;

        int64_t cost = 1e9;
        int zoo_id = -1;
        for (int i = 0; i < n; ++i) {
            if (zoo.at(i).at(animal.second) == 1 && cost > c.at(i).first) {
                cost = (int64_t)c.at(i).first;
                zoo_id = c.at(i).second;
            }
        }

        ans += cost * want_look_animals.at(animal.second);

        for (int i = 0; i < m; ++i) {
            if (zoo.at(zoo_id).at(i) == 1) {
                --want_look_animals.at(i);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
