#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, a, x;
    cin >> q;

    map<int, int> bags;

    for (int Q = 0; Q < q; ++Q) {
        cin >> a;

        if (a == 1) {
            cin >> x;
            if (bags.count(x)) {
                ++bags.at(x);
            } else {
                bags[x] = 1;
            }
        } else if (a == 2) {
            cin >> x;
            --bags.at(x);
            if (bags.at(x) == 0) {
                bags.erase(x);
            }
        } else if (a == 3) {
            cout << bags.size() << endl;
        }
    }

    return 0;
}
