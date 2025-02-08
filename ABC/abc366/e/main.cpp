#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; ++i) {
        cin >> points.at(i).first >> points.at(i).second;
    }

    return 0;
}
