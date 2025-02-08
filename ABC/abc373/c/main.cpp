#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a.at(i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> b.at(i);
    }

    cout << *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end())
         << endl;

    return 0;
}
