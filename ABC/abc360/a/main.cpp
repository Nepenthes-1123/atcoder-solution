#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < 3; i++) {
        if (s.at(i) == 'M') {
            cout << "No" << endl;
            break;
        } else if (s.at(i) == 'R') {
            cout << "Yes" << endl;

            break;
        }
    }
}
