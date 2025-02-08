#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, count = 0;

    cin >> s;

    for (int i = 0; i < 3; i++) {
        if (s % 10 == 1) {
            count++;
        }
        s /= 10;
    }

    cout << count << endl;
}
