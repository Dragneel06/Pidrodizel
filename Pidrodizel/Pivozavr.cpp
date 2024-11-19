#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Обчислення ряду для f(x) = -1/2 * ln(1 - 2x * cos(pi/3) + x^2)\n";

   
    const double x_min = 0.0;    
    const double x_max = 1.0;    
    const double step = 0.1;     
    const int N = 10;            

    
    const double cos_pi_3 = std::cos(M_PI / 3);

    
    for (double x = x_min; x <= x_max; x += step) {
        double S = 0.0;  

        
        for (int n = 1; n <= N; ++n) {
            double term = pow(x, n) / n * std::cos(n * M_PI / 3); 
            S += term;
        }

        
        double exact = -0.5 * std::log(1 - 2 * x * cos_pi_3 + x * x);

        
        std::cout << "x = " << x << ", S = " << S << ", Точне значення = " << exact
            << ", Похибка = " << fabs(S - exact) << "\n";
    }

    return 0;
}