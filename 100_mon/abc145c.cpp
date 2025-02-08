#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N), ord(N);

    for (int i = 0; i < N; ++i) {
        cin >> X.at(i) >> Y.at(i);
        ord.at(i) = i;
    }

    long double sm = 0;
    do {
        for (int i = 0; i < N - 1; ++i) {
            int a = ord.at(i);
            int b = ord.at(i + 1);

            long double dx = X.at(a) - X.at(b);
            long double dy = Y.at(a) - Y.at(b);

            sm += sqrt(dx * dx + dy * dy);
        }
    } while (next_permutation(ord.begin(), ord.end()));

    for (int i = 0; i < N; ++i) {
        sm /= (i + 1);
    }

    cout << fixed << setprecision(10) << sm << endl;
}
