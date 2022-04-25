#include "vector_ops.hpp"
double mean(const std::vector<double> & data){
    int N = data.size();
    double sum = 0;
    for(int k=0; k<N; k++){
        sum += data[k];
    }
    double mean = sum/N;
    return mean;
}
