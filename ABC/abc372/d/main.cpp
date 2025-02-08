#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);

    for (int &h_i : h) {
        cin >> h_i;
    }

    for (int i = 0; i < n; ++i) {
        int highest = 0, cnt = 0;
        for (int j = i + 1; j < n; ++j) {
            if (highest < h.at(j)) ++cnt;
            highest = max(highest, h.at(j));
        }
        cout << cnt << " ";
    }

    cout << endl;

    return 0;
}
