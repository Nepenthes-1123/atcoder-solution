#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> vec, int key) {
    int left = 0, right = (int)vec.size(), mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (vec[mid] == key) {
            return mid;
        } else if (key < vec[mid]) {
            right = mid;
        } else if (vec[mid] < key) {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S.at(i);
    }

    int q, cnt = 0;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int T;
        cin >> T;
        if (binarySearch(S, T) != -1) ++cnt;
    }
    cout << cnt << endl;
}
