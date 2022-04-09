#include <iostream>

int main(int argc, char **argv)
{
  double x[10], y[5]; // LA: imprime raro
  /*Cuando se declaran de esta manera el compilador pide memoria de forma tal
   *que:
   *|BASURA|y[0]|y[1]|y[2]|y[3]|y[4]|BASURA|x[0]|x[1]|...|x[9]|BASURA|*/

  // double y[5], x[10]; // LB: imprime 1
  /*Mientras que cuando se declaran de esta otra, lo pide así:
   *
   *|x[0]|x[1]|...|x[9]|y[0]|y[1]|y[2]|y[3]|y[4]|BASURA*/
  for(int ii = 0; ii < 5; ++ii) {
    y[ii] = ii +1;
  }
  for(int ii = 0; ii < 10; ++ii) {
    x[ii] = -(ii +1);
  }
  /*CORRECCIÓN:
   *En la linea 22 se intenta leer memoria fuera del arreglo, por
   *tanto sin importar si se usa LA o LB se lee a 10 posiciones de x[0], que es
   *una dirección de memoria que no hemos especificado y el compilador hace
   *con ella lo que le parezca. La forma de arreglar esto es especificar
   *el valor que está guardado en la dirección de memoria x[10]*/
  double * ptr = &x[10]; //puntero a la dirección de memoria de x[10]
  ptr[0] = y[0]; //fijamos el valor para que coincida siempre con el de y[0]
  double z = x[10]; //se intenta acceder a memoria fuera del arreglo
  std::cout << z << std::endl;

  return 0;
}
