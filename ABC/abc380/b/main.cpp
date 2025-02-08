#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> A;

    int a = 0;
    for (char c : s) {
        if (c == '|' && a != 0) {
            A.push_back(a);
            a = 0;
        } else if (c == '-') {
            ++a;
        }
    }
    for (int i = 0; i < (int)A.size(); ++i) {
        cout << A.at(i) << " ";
    }
    cout << endl;

    return 0;
}
