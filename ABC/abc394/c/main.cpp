#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string pre_c = "";
    for (int i = 0; i < (int)s.size(); ++i) {
        if (pre_c + s.at(i) == "WA") {
            s.at(i - 1) = 'A';
            s.at(i) = 'C';
            i -= 2;
            if (i < 0) i = 0;
        }

        pre_c = s.at(i);
    }

    cout << s << endl;

    return 0;
}
