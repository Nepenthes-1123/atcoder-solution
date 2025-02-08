#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int64_t t = 0;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h.at(i);
    }

    for (int hp : h) {
        t += (hp / 5) * 3;
        hp %= 5;
        while (hp > 0) {
            ++t;
            if (t % 3 == 0) {
                hp -= 3;
            } else {
                --hp;
            }
        }
    }

    cout << t << endl;

    return 0;
}
