#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int count = 1;

    char op;

    // ここにプログラムを追記
    for (int i = 1; i < S.size(); i += 2) {
        op = S.at(i);
        if (op == '+') {
            count++;
        } else if (op == '-') {
            count--;
        }
    }

    cout << count << endl;
}
