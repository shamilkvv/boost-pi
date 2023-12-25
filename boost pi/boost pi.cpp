#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>

using s_float = boost::multiprecision::cpp_dec_float_100;

s_float power(const s_float& base, int exponent) {
    if (exponent < 0) {
        std::cerr << "Negative exponent\n";
        return 0;
    }

    s_float result = 1.0;

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    return result;
}

s_float boost_factorial(int num);

s_float ramanujan_formula_term(int k) {
    s_float result1 = power(396.0, 4 * k);
    s_float result2 = power(boost_factorial(k), 4);

    s_float n = boost_factorial(4 * k) * (1103 + (26390 * k));
    s_float m = result1 * result2;

    return n / m;
}

s_float boost_factorial(int num) {
    s_float fact = 1;

    for (int i = num; i > 1; --i) {
        fact *= i;
    }

    return fact;
}


int main() {
    s_float pi_ramanujan = 0;
    s_float z = sqrt(8) / 9801;

    for (int k = 0; k < 100; ++k) {
        pi_ramanujan += ramanujan_formula_term(k);
    }

    pi_ramanujan = 1 / (pi_ramanujan * z);

    std::cout << "Ramanujan: " << pi_ramanujan << "\n";

    s_float pi_boost = boost::math::constants::pi<s_float>();
    std::cout << "Boost: " << pi_boost << "\n";

    s_float diff = fabs(pi_ramanujan - pi_boost);
    std::cout << "Difference: " << diff << "\n";

    return 0;

    return 0;
}
