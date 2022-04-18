#include <cmath>
#include <cstdlib>
#include <iostream>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);

int main(int argc, char **argv) {
  int ii, jj;
  ii = 1;
  jj = 1;
  foo(ii, jj);
  foo(jj, ii);
  baz(25.9);

  return EXIT_SUCCESS;
}

int foo(int a, int b) { return a / b + b / bar(a, b) + b / a; }

int bar(int a, int b) {
  int c = a;
  return c + a - b;
}

double baz(double x) {
  if (x == 0) {
    return 0;
  }
  // double v = 1-(x+1);
  return std::sqrt(x);
}
