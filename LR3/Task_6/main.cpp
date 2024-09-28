#include <iostream>
#include <cmath>

int factorial( double n){

    return (n==0) || (n==1) ? 1 : n * factorial(n-1);
}

double sinus(double x) {
    double x_1 = x * 180/ M_PI;
    if (x_1 >= 90) {
        x_1 = 180 - x_1;;
    }
    if (x_1 <= -90) {
        x_1 = -1 *(180 + x_1);
    }
    x_1 = x_1 * M_PI / 180;
    double y{0};
    for (int i = 0; i <= 20; i++) {
        y +=  pow(-1, i) * (pow(x_1, 2 * i  + 1)) / factorial(2 * i + 1);
    }
    return y;
}

double cosus(double x) {
    double x_1 = x * 180/ M_PI;;
    double y{0};
    int minus{1};
    x_1 = x_1 < 0? -1 * x_1 : x_1;
    if(x_1 > 90) {
        x_1 = 180 - x_1;
        minus = -1;;
    }

    x_1 = x_1 * M_PI / 180;
    for(int i = 0 ; i <= 20; i++) {
        y += pow(-1, i) * (pow(x_1, 2 * i)) / factorial(2 * i);
    }
    return y * minus;
}

double logos(double x) {

        double x_1 = x <  0? -1 * x : x;
        double ratio = (x_1 - 1) / (x_1 + 1);

        double accumul = ratio;

        double total = accumul;

        int power = 3;
        int n = 20;
        while (power < n) {

            accumul *= ratio;

            accumul *= ratio;

            total += (1 / (double) power) * accumul;

            power += 2;
        }

        return 2.0 * total;

}


int main() {
    double ugol;

    std::cin >> ugol;
    ugol = ugol - (int)(ugol / 180) * 180;
    std::cout << ugol<< std::endl;
    std::cout << sinus(ugol * M_PI / 180) << std::endl;
    std::cout << sin(ugol * M_PI / 180) << std::endl;
    std::cout << cosus(ugol * M_PI / 180) << std::endl;
    std::cout << cos(ugol * M_PI / 180) << std::endl;
    std::cout << logos(ugol * M_PI / 180) << std::endl;
    std::cout << log(fabs(ugol * M_PI / 180)) << std::endl;
}
