#include <iostream>
#include <cmath>
#include <limits>

int main() {
    float inf = std::numeric_limits<float>::infinity();
    float nan = std::numeric_limits<float>::quiet_NaN();
    float zero = 0.0f;

    std::cout << "X - (+∞): " << 10.0f - inf << "\n";
    std::cout << "(+∞) - (+∞): " << inf - inf << "\n";
    std::cout << "X / 0: " << 10.0f / zero << "\n";
    std::cout << "0 / 0: " << zero / zero << "\n";
    std::cout << "∞ / ∞: " << inf / inf << "\n";
    std::cout << "sqrt(X) với X < 0: " << sqrt(-1.0f) << "\n";

    return 0;
}