#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> x(q);
    vector<char> c(q);

    for (int i = 0; i < q; ++i) {
        cin >> x.at(i) >> c.at(i);
    }

    int cnt = 0, pos = s.find("ABC");
    while (pos != -1) {
        pos = s.find("ABC", pos + 2);
        ++cnt;
    }

    string ss;
    int j;
    for (int i = 0; i < q; ++i) {
        j = max(x.at(i) - 3, 0);
        ss = s.substr(j, 5);
        pos = ss.find("ABC");
        if (pos != -1) --cnt;

        s.at(x.at(i) - 1) = c.at(i);

        ss = s.substr(j, 5);
        pos = ss.find("ABC");
        if (pos != -1) ++cnt;

        cout << cnt << endl;
    }

    return 0;
}
