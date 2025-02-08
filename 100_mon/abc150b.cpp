#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, count = 0;
    string S;
    cin >> N >> S;
    for (int i = 0; i < N - 2; ++i) {
        if (S.at(i) == 'A') {
            if (S.substr(i, 3) == "ABC") {
                ++count;
            }
        }
    }
    cout << count << endl;

    return 0;
}
