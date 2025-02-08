#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());

    int head = 0, tail = A.size() - 1;

    for (int i = 0; i < K; ++i) {
        if (head == tail) break;
        if (A.at(head + 1) - A.at(head) > A.at(tail) - A.at(tail - 1)) {
            ++head;
        } else {
            --tail;
        }
    }

    cout << A.at(tail) - A.at(head) << endl;
}
