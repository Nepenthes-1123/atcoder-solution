#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double ax, ay, az;
    double bx, by, bz;
    double n;

    std::cin >> ax >> ay >> az >> bx >> by >> bz >> n;

    double dx, dy, dz;
    dx = bx - ax;
    dy = by - ay;
    dz = bz - az;

    double len = sqrt(dx * dx + dy * dy + dz * dz);

    std::cout << sqrt((dx / len) * (dx / len) + (dy / len) * (dy / len) +
                      (dz / len) * (dz / len))
              << std::endl;

    dx /= len;
    dy /= len;
    dz /= len;

    double cx, cy, cz;

    cx = dx * n + ax;
    cy = dy * n + ay;
    cz = dz * n + az;

    std::cout << std::fixed << cx << " " << std::fixed << cy << " "
              << std::fixed << cz << std::endl;

    return 0;
}
