#include <Eigen/Dense>
#include <chrono>
#include <iostream>
#include <cmath>
double multiply(int size);
void fill_vector(Eigen::VectorXd &v, int size);
double average(int size, int N);
double standard_deviation(Eigen::VectorXd &v);
int main(int argc, char **argv){
      const int N = 100; //amount of repetitions to be done for each size
      const int SIZE = std::atoi(argv[1]); //maximum size to use
      //print the header of the file
      // std::cout << "L" << "\t" << "mean_time" << "\t" << "sigma" << "\n";

      Eigen::VectorXd v;  //array to store the information
      v.resize(N,1);
      fill_vector(v, SIZE);
      //now print the size used, the mean time and the standard deviation
      double mean_time = v.mean();
      double sigma = standard_deviation(v);
      std::cout <<SIZE << "\t" << mean_time << "\t" << sigma <<"\n";

      return 0;
}


double multiply(int size){
      //create matrices
      std::cout.precision(16); std::cout.setf(std::ios::scientific);
      Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
      Eigen::MatrixXd B = Eigen::MatrixXd::Random(size, size);

      auto start = std::chrono::steady_clock::now();
      auto C{A*B}; //MULTIPLY
      double tmp = C(0,0);//use the matrix so eigen computes it
      auto end = std::chrono::steady_clock::now();
      std::chrono::duration<double> elapsed_seconds = end-start;
      return elapsed_seconds.count();
    }

void fill_vector(Eigen::VectorXd &v, int size){
      for (auto &x : v){
            x = multiply(size);
      }
      return;
}

double standard_deviation(Eigen::VectorXd &v){
      int L = v.size();
      double sum = 0;
      double mean = v.mean();
      for (auto &x : v){
            sum += std::pow(x - mean, 2);
      }
      double sigma = std::sqrt( sum/L );
      return sigma;
}
