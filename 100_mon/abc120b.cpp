#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, K, count = 0;
    cin >> A >> B >> K;

    for (int i = A; i > 0; --i) {
        int div = i;
        if (A % div == 0 && B % div == 0) {
            ++count;
            if (count == K) cout << div << endl;
        }
    }
}
