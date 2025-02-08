#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 0, a = 0, b = 0;
    cin >> x >> a >> b;

    // 1.の出力
    x++;
    cout << x << endl;

    // ここにプログラムを追記
    x *= a + b;
    cout << x << endl;

    x *= x;
    cout << x << endl;

    cout << --x << endl;
}
