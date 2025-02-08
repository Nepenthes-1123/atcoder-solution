#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> c;
    int x;

    while (cin >> x) {
        if (x != 0)
            c.push_back(x);
        else
            break;
    }

    for (int i = 0; i < (int)c.size(); ++i) {
        cout << "Case " << i + 1 << ": " << c.at(i) << endl;
    }
}
