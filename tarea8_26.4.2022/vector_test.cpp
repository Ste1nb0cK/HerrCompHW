#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include <cmath>
#include <algorithm>
#include "vector_ops.hpp"
TEST_CASE( "Mean of a vector is computed", "[mean]" ) {
    //REQUIRE( factorial(0) == 1 );
    // crear vectores de prueba y comprobar los resultados con REQUIRE
    const double EPS = 1E-3; //desired precision
    const int N = 10; //size of the vectors used in the test
    const double a = 77;
    std::vector<double> zero_vector(N, 0); //initialzie a vector full of zeros
    std::vector<double> ones_vector(N, 1); // std::vector<double> N_naturals_vector;
    std::vector<double> N_naturals_vector;
    N_naturals_vector.resize(N);
    std::iota(N_naturals_vector.begin(), N_naturals_vector.end(), 0.0);
    std::vector<double> vector1;
    vector1.resize(N);
    std::fill(vector1.begin(), vector1.end(), a);
    REQUIRE( std::abs(mean(zero_vector) - 0.0) < EPS);
    REQUIRE( std::abs(mean(ones_vector) - 1.0) < EPS);
    /*The sum of the first N natural numbers (beginning at zero) is well known
     *to be S_N = N*(N-1)/2 and thus its average is <S_N>=(N-1)/2. We use this
     *analytical result to test our function.*/
    REQUIRE( std::abs(mean(N_naturals_vector)-(N-1)/2.0 ) < EPS);
    std::reverse(N_naturals_vector.begin(), N_naturals_vector.end());
    REQUIRE( std::abs(mean(N_naturals_vector)-(N-1)/2.0 ) < EPS);
    REQUIRE( std::abs(mean(vector1) - a ) < EPS);
    /*The result should not change if the order of the vector is inverted*/
}
