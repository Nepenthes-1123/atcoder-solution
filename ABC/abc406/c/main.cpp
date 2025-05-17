#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<bool> head(n, false), grt(n, false), lsr(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> p.at(i);
    }

    if (p.at(0) < p.at(1)) head.at(0) = true;

    for (int i = 1; i < n - 1; ++i) {
        if (p.at(i) < p.at(i + 1)) {
            head.at(i) = true;
            if (p.at(i) < p.at(i - 1)) lsr.at(i) = true;
        }
        if (p.at(i - 1) < p.at(i) && p.at(i) > p.at(i + 1)) grt.at(i) = true;
    }

    for (int i = 0; i < n; ++i) {
    }

    return 0;
}
