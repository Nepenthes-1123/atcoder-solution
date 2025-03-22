#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> A;

    for (int i = 0; i < 13; ++i) {
        A[i] = 0;
    }

    for (int i = 0; i < 7; ++i) {
        int a;
        cin >> a;

        A.at(--a)++;
    }

    bool three = false, two = false;

    for (int i = 0; i < 13; ++i) {
        if (A.at(i) >= 3 && !three) {
            three = true;
        } else if (A.at(i) >= 2) {
            two = true;
        }
    }

    if (three && two) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
