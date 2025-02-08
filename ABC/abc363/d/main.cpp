#include <bits/stdc++.h>
using namespace std;

void check(vector<int> vec, int key) {
    if (key == (int)vec.size()) {
        vec.push_back(1);
    }
    if (vec.at(key) > 9) {
        vec.at(key) %= 10;
        ++vec.at(key + 1);
        check(vec, key + 1);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> tree;

    if (N <= 10) {
        cout << N - 1 << endl;
    } else if (N < 20) {
        cout << N % 10 << N % 10 << endl;
    } else {
        N -= 19;
        tree.push_back(0);
        tree.push_back(1);

        for (int i = 0; i < N; ++i) {
            ++tree.at(0);
            check(tree, 0);
        }
    }
    for (int t : tree) {
        cout << t << " ";
    }
    cout << endl;
}
