#include <bits/stdc++.h>
using namespace std;

int main() {
    string ab, ac, bc, scnd;

    cin >> ab >> ac >> bc;

    if (ab == "<") {
        if (ac == "<") {
            if (bc == "<") {
                scnd = "B";
            } else {
                scnd = "C";
            }
        } else {
            scnd = "A";
        }
    } else {
        if (bc == "<") {
            if (ac == "<") {
                scnd = "A";
            } else {
                scnd = "C";
            }
        } else {
            scnd = "B";
        }
    }

    cout << scnd << endl;
    

    return 0;
}
