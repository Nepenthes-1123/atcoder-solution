#include <bits/stdc++.h>
using namespace std;

int main() {
    uint64_t n, k;
    cin >> n >> k;

    uint64_t ans = 1;

    for (int i = 0; i < n; ++i) {
        uint64_t a;
        cin >> a;

        if (ans * a == 0 || floor(log10(ans) + log10(a)) + 1 > k) {
            ans = 1;
        } else
            ans *= a;
    }

    cout << ans << endl;
    return 0;
}

// python
// n, k = map(int, input().split())
// a_list = list(map(int, input().split()))

// ans = 1
// limit = 10 ** k

// for a in a_list:
//     if ans * a >= limit:
//         ans = 1
//     else:
//         ans *= a

// print(ans)
