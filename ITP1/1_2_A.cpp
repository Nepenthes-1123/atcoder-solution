#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string op;

    if (a < b) {
        op = "a < b";
    } else if (b < a) {
        op = "a > b";
    } else if (a == b) {
        op = "a == b";
    }

    cout << op << endl;
}
