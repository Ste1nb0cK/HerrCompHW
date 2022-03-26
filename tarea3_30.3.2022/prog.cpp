#include<iostream>
#include<cmath>
/* harmonic(int m)
** Description: routine that calculates the harmonic series up to N
** Input: int n, representing the amount of terms. It is assumed n>0.
** Output: double, armonic sum
*/
double harmonic(int m);

/* gamma_m(int m)
** Description: routine that aproximates gamma with m term
** Input: intm, amount of terms to be used. It is assumed m>0
** Outout: double, gamma aproximated with m terms using the sum definition
*/
double gamma_m(int m);

int main(void){
    const int N = 5000; //number of iterations
    const int N_print = 100; //intermediate answers are printed each N_print steps
    std::cout.precision(12);
    std::cout.setf(std::ios::scientific);
    std::cout << "n\t" << "gamma_n\n";
    for(int k=1; k <= N/N_print; k++){
        int m = k*N_print;
        std::cout << m <<"\t"<< gamma_m(m) << std::endl;
    }
    return 0;
}

double harmonic(const int n){
    double sum = 0;
    for(int k = n; k>=1; k--){
        sum += 1.0/k;
            }
    return sum;
}

double gamma_m(int m){
    return harmonic(m) - std::log(m);
}
