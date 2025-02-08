#include <bits/stdc++.h>
using namespace std;

double deg2rad(double deg) { return deg * M_PI / 180.0; }

int main() {
    int a, b, x, y, r, theta, l;
    cin >> a >> b >> x >> y >> r >> theta >> l;
    double theta_d = deg2rad(theta);

    double dx = l * cos(theta_d) + (x - r);
    double dy = l * sin(theta_d) + (y - r);

    double pad_a = a - 2 * r;
    double pad_b = b - 2 * r;

    dx = fmod(dx, 2 * pad_a);
    if (dx < 0) dx += 2 * pad_a;

    dy = fmod(dy, 2 * pad_b);
    if (dy < 0) dy += 2 * pad_b;

    double x_t = dx <= pad_a ? dx + r : a - (dx - pad_a) - r;
    double y_t = dy <= pad_b ? dy + r : b - (dy - pad_b) - r;

    cout << fixed << setprecision(13) << x_t << " " << fixed << setprecision(13)
         << y_t << endl;
}
