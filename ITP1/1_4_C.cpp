#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, ans;
    string op;

    while (cin >> a >> op >> b) {
        if (op == "+") {
            ans = a + b;
        } else if (op == "-") {
            ans = a - b;
        } else if (op == "*") {
            ans = a * b;
        } else if (op == "/") {
            ans = a / b;
        } else if (op == "?") {
            return 0;
        }
        cout << ans << endl;
    }
}
