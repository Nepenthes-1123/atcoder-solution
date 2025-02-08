#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    string sentence = "";

    for (int w = 1; w < (int)S.size() - 1; w++) {
        for (int c = 0; c <= w; c++) {
            sentence = "";
            for (int i = 0; w * i + c < (int)S.size(); i++) {
                sentence += S.at(w * i + c);
            }
            if (sentence == T) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    if (sentence != T) {
        cout << "No" << endl;
    }
    return 0;
}
