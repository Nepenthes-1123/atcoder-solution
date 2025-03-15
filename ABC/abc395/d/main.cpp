#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    map<int, int> birds;
    // 鳩番号を引数に、所属先の巣を返す

    map<int, vector<int>> nests;
    // 巣番号を引数に、所属する鳩のリストを返す。

    vector<int> call;

    for (int i = 0; i < n; ++i) {
        birds[i] = i;
        nests[i] = {i};
    }

    int op;
    for (int i = 0; i < q; ++i) {
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            int now_nest = birds.at(a);
            birds.at(a) = b;
            nests.at(now_nest).erase(
                remove(nests.at(now_nest).begin(), nests.at(now_nest).end(), a),
                nests.at(now_nest).end());
            nests.at(b).push_back(a);

        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;

            for (int bird : nests.at(a)) {
                birds.at(bird) = b;
            }
            for (int bird : nests.at(b)) {
                birds.at(bird) = a;
            }

            swap(nests.at(a), nests.at(b));

        } else if (op == 3) {
            int a;
            cin >> a;
            --a;
            call.push_back(birds.at(a) + 1);
        }
    }

    for (int nest : call) {
        cout << nest << endl;
    }

    return 0;
}
