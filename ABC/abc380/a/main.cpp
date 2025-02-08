#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    int count1 = 0, count2 = 0, count3 = 0;

    for (char c : n) {
        if (c == '1') {
            ++count1;
        } else if (c == '2') {
            ++count2;
        } else if (c == '3') {
            ++count3;
        }
    }

    if (count1 == 1 && count2 == 2 && count3 == 3) {
        cout << "Yes" << endl;
        
    } else {
        cout << "No" << endl;
    }

    return 0;
}
