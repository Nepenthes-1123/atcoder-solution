#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, count = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string n = to_string(i + 1);
        if ((int)n.length() % 2 == 1) {
            ++count;
        }
    }

    cout << count << endl;
}
