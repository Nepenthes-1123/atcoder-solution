#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, X;
    cin >> N >> K >> X;

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;

        cout << a;
        if (i != N) cout << " ";
        if (i + 1 == K) cout << X;
        if (i + 1 == K && i != N) cout << " ";
    }
    cout << endl;
}
