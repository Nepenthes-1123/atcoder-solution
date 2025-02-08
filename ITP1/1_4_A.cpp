#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    double f = (double)a / (double)b;

    cout << a / b << " " << a % b << " " << fixed << setprecision(5) << f
         << endl;
}
