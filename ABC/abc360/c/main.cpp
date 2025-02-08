#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), W(N);

    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> W.at(i);
    }

    map<int, int> pair;
    int sum_cost = 0;

    for (int i = 0; i < N; i++) {
        int a = A.at(i);
        int w = W.at(i);

        if (pair.count(a)) {
            sum_cost += min(pair.at(a), w);
            pair.at(a) = max(pair.at(a), w);
        } else {
            pair.insert(make_pair(a, w));
        }
    }

    cout << sum_cost << endl;
}
