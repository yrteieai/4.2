#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x, xp, xk, dx, y;

    cout << "Entering the initial value X: "; cin >> xp;
    cout << "Entering the final value X: "; cin >> xk;
    cout << "Entering a step dX: "; cin >> dx;

    // заголовок таблиці
    cout << fixed;
    cout << "-----------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |" << setw(12) << "y" << " |" << endl;
    cout << "-----------------------------------" << endl;

    // цикл для обчислення значень
    x = xp;
    while (x <= xk) {
        if (x < 0) {
            // перша гілка: x^7 - 2x для x < 0
            y = x * x * x * x * x * x * x - 2 * x; // x^7 - 2x
        }
        else if (x >= 0 && x < 3) {
            // друга гілка: |4x-1| + arctg((e^x + 1) / 8) для 0 ≤ x < 3
            y = fabs(4 * x - 1) + atan((exp(x) + 1) / 8);
        }
        else {
            // третя гілка: x^4 + e^(x^2 + 3) для x ≥ 3
            y = x * x * x * x + exp(x * x + 3); // x^4 + e^(x^2 + 3)
        }

        // значення x та y
        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(12) << setprecision(5) << y << " |" << endl;

        // збільшення x на крок
        x += dx;
    }

    cout << "-----------------------------------" << endl;

    return 0;
}
