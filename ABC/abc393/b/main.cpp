#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s.at(i) == 'B') {
            for (int j = 1; j <= min(i, (int)s.size() - i - 1); ++j) {
                if (s.at(i - j) == 'A' && s.at(i + j) == 'C') ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}
