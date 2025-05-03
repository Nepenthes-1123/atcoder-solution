#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> char_count;

    for (char c : s) {
        char_count.insert(c);
    }

    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;

        if (!char_count.count(c)) {
            cout << c << endl;
            return 0;
        }
    }

    return 0;
}
