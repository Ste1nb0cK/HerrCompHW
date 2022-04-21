# include <iostream>
# include <cstdlib>
# include <cmath>
# include "factorial.h"
// funcion main: archivo factorial_main.cpp
int main(int argc, char *argv[])
{
const double n = std::atof(argv[1]);
std::cout << factorial(n) << "\n";
return 0;
}
