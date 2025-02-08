#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 0, sum = 0, ave = 0;
    cin >> N;

    vector<int> point(N);

    for (int i = 0; i < N; i++) {
        cin >> point.at(i);
        sum += point.at(i);
    }

    ave = sum / N;

    for (int i = 0; i < N; i++) {
        if (point.at(i) > ave) {
            cout << point.at(i) - ave << endl;
        } else {
            cout << ave - point.at(i) << endl;
        }
    }
}
