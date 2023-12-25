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


int main() {
 

    return 0;
}
