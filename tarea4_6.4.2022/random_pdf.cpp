#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits> //para usar los valores de precisión de máquina
#include <fstream> //para escribir a archivos
#include <cmath> //para usar la función floor
#include <map> //nuestro histograma será un map, entonces necesitamos esto.
#include <string> //para personalizar el nombre del archivo de texto
void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

/*obtain_bin(x, xmin, xmax, nbins)
 *Determina en que bin se encuentra x.
 *INPUT: double x, número que deseamos saber a cual bin pertenece
 *       double xmin, valor mínimo del rango en que se está calculando la pdf
 *       double xmax, valor máximo del rango en que se está calculando la pdf
 *       int nbins, cantidad de bins
 *OUTPUT: int bin, número del bin en que se encuentra x.
 *
 *Anotaciones: todos los bins tienen el mismo tamaño
 *             y la indexación de estos empieza en 0. Se asume xmax>=x>=xmin. */
int obtain_bin(double x, double xmin, double xmax, int nbins);

/*in_range(x, xmin, xmax)
*determina si x se encuentra dentro de [xmin, xmax].
* INPUT: double x, número que deseamos saber si está en el rango.
*        double xmin, valor minimo del rango.
*        double xmax, valor máximo del rango.
*
* OUTPUT: bool is_in, booleano con un true si está en el rango y un salse si no.
*
*Anotaciones: se asume que xmax>xmin.
*/
bool in_range(double x, double xmin, double xmax);


int main(int argc, char **argv){
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);
  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
  return 0;
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  // TODO: histogram stuff
  /*Declaramos el histograma. La llave representa el indice del bin y el valor
   *de esta la cantidad de números en el bin, lo llamamos contador.*/
  std::map<int, int> histogram;
  /*Pasamos a crear tantos elementos en el histograma como bins halla, cada
   *bin empieza con 0 en el contador. */
  for(int m=0; m<nbins; m++){
    histogram.insert({m, 0});
  }
  //index del bin al que vamos a añadir elementos. Esto es para el loop.
  int bin = 0;
  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    // TODO: fill here the counting histogram
    // std::cout << r << std::endl;
    // determinamos si r está en el rango, si no lo está pasamos al siguiente.
    if(not in_range(r, xmin, xmax)){continue;}
    //determinamos el bin al que pertenece r y aumentamos su contador.
    bin = obtain_bin(r, xmin, xmax, nbins);
    histogram[bin]++;
  }
  // TODO: compute and print the pdf
  //abrimos el archivo en el que vamos a guardar el histograma
  std::string filename = "pdf" + std::to_string(seed)+".txt";
  std::fstream OutputFile;
  OutputFile.open(filename, std::ios::out);
  /*Inicializamos variables para el centro del bin, el valor que toma la pdf
   *en este, y el tamaño de los bins. Asociamos la densidad de probabilidad
   *del bin con el valor que toma la pdf en el centro de este.*/
  const double dx = (xmax - xmin)/nbins;
  double x =xmin + dx/2;
  double pdf_at_x = (histogram[0]+0.0)/(nsamples*dx);
  /*inicializamos el loop imprimiendo la primera linea fuera del loop.
   *Esto evita que el loop cálcule el centro del último bin como si
   *estuviera fuera del rango y de paso ponemos el nombre de las columnas.*/
  OutputFile << "x" << "\t" << "rho(x)" << std::endl;
  OutputFile << x << "\t" << pdf_at_x << std::endl;
  for(int k = 1; k < nbins; k++){
    x += dx;
    pdf_at_x = (histogram[k] + 0.0)/(nsamples*dx);
    OutputFile << x << "\t" << pdf_at_x << std::endl;
  }
  OutputFile.close();
}

int obtain_bin(double x, double xmin, double xmax, int nbins){
  const double dx = (xmax - xmin)/nbins; //tamaño de los bins
  const double xrel = x - xmin; //posición relativa a xmin
  const int bin = std::floor(xrel/dx); //cantidad de bins que caben entre x y xmin
  return bin;
}

bool in_range(double x, double xmin, double xmax){
  bool is_in =true; //bandera que dice si está dentro del rango o no.
  /*definimos una variable con el epsilon de los double. Esta es la diferencia
  entre 1.0 y el siguiente número representable mediante doubles.
  Referencia: https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon*/
  const double ESP = std::numeric_limits<double>::epsilon();
  //determinamos si al representarse como double encontramos a x en el rango.
  if((x- xmin >= ESP)&(xmax - x >= ESP)){return is_in;}
  else{
    is_in=false;
    return is_in;}
}
