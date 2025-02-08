#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;

    if ((((a < g && g < d) || (a < j && j < d)) &&
         ((b < h && h < e) || (b < k && k < e)) &&
         ((c < i && i < f) || (c < l && l < f))) ||
        (((g < a && a < j) || (g < d && d < j)) &&
         ((h < b && b < k) || (h < e && e < k)) &&
         ((i < c && c < l) || (i < f && f < l))) ||
        (a == g && b == h && c == i && d == j && e == k && f == l) ||
        ((((a < g && g < d) || (a < j && j < d)) ||
          ((g < a && a < j) || (g < d && d < j))) &&
         b == h && c == i && e == k && f == l) ||
        (((((b < h && h < e) || (b < k && k < e)) || (h < b && b < k) ||
           (h < e && e < k))) &&
         a == g && c == i && d == j && f == l) ||
        ((((c < i && i < f) || (c < l && l < f)) ||
          ((i < c && c < l) || (i < f && f < l))) &&
         a == g && b == h && d == j && e == k)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
