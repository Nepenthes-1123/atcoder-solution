#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> pairs;
    int a, b;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        pairs.push_back(make_pair(b, a));
    }

    sort(pairs.begin(), pairs.end());

    for (int i = 0; i < N; i++) {
        tie(b, a) = pairs.at(i);
        cout << a << " " << b << endl;
    }
}
