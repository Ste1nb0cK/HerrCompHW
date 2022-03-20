#include<cmath>
#include<iostream>
#include<string> //para comparar texto
#include<iomanip> //para formatear la impresión


/* 
double roots(double a,double b,double c,int root_sign,std::string method)
 *Input:
 *      double a,b,c. Coeficientes de la ecuación cuadrática
 *      int root_sign. Signo de la raíz a retornar, los valores validos son 1,-1
 *      std::string method. Opcional, String que define el método a usar,
 *                          "smart" o "naive". Debe pasarse como se muestra,
 *                          sin espacios. Si no se especifica se usa
 *                          smart.
 *Output:
         double y. Valor de la raíz indicada, calculada con el método escodigo.
                   En caso de que no haya raíces reales, retorna un 1 e
                   imprime a stdout el mensaje de que no hay raíces reales.
  */
double roots(double a, double b, double c, int root_sign, //
             std::string method="smart");

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific); // imprimir con formato de notación científica
    double a = 1;
    double b = 1;
    double c = 0; // inicializar variables
/*basado en lo propuesto en
*https://stackoverflow.com/questions/22981618/aligning-output-on-the-right-in-c
* para que el nombre de las columnas esté bien alineado*/
    std::cout << std::left << std::setw(25)<< "c" //se usa 25 porque 15 queda feo
              <<std::left << std::setw(25)<< "x_{+}"
              <<std::left << std::setw(25)<< "x_{-}"
              <<std::left << std::setw(25)<< "x_{+}'"
              <<std::left << std::setw(25)<< "x_{-}'" << std::endl;
    for (int n=0; n<=10; n++){
        c = std::pow(10, -n);
        std::cout << c << "\t"
                  << roots(a,b,c, +1, "naive") << "\t"
                  << roots(a,b,c, -1, "naive") << "\t"
                  << roots(a,b,c, +1, "smart") << "\t"
                  << roots(a,b,c, -1, "smart") << std::endl;
    }
    return 0;
}


double roots(double a, double b, double c, int root_sign,
             std::string method){
    double det = std::pow(b,2) - 4*a*c; //determinante
    //Signbit devuelve true si el argumento tiene signo negativo
    if(std::signbit(det)){
        std::cout << "No hay raíces reales ";
        return 1;
    }
    if (method == "naive"){
        double y = (-b + root_sign*std::sqrt(det))/(2*a);
        return y;}
    else if (method == "smart"){
            double y = (-2*c)/(b+root_sign*std::sqrt(det));
            return y;}
    return 1;
}
