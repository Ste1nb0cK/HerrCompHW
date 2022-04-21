#include "factorial.h"
double factorial(double m)
{
    if (m <= 1) {return 1;}
    return m*factorial(m-1);
}
