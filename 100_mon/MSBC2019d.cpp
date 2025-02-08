#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, count = 0;
    string S;
    cin >> N >> S;

    for (int i = 0; i < 1000; ++i) {
        int dig = 0;
        string key = to_string(i / 100 % 10) + to_string(i / 10 % 10) +
                     to_string(i % 10);
        for (int j = 0; j < N; ++j) {
            if (key.at(dig) == S.at(j)) {
                ++dig;
            }
            if (dig == 3) {
                break;
            }
        }
        if (dig == 3) ++count;
    }

    cout << count << endl;
}
