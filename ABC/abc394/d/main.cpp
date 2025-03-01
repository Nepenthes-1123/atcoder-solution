#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string brackets;

    for (char c : s) {
        if (c == ')') {
            if ((int)brackets.size() > 0 && brackets.back() == '(') {
                brackets.pop_back();
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else if (c == ']') {
            if ((int)brackets.size() > 0 && brackets.back() == '[') {
                brackets.pop_back();
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else if (c == '>') {
            if ((int)brackets.size() > 0 && brackets.back() == '<') {
                brackets.pop_back();
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            brackets.push_back(c);
        }
    }

    if ((int)brackets.size() == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
