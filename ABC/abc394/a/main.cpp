#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;

    for (char c : s) {
        if (c == '2') ++count;
    }

    for (int i = 0; i < count; ++i) {
        cout << 2;
    }

    cout << endl;

    return 0;
}
