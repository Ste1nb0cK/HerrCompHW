#include <cstdio>
#include <cstdlib>

/*
  Tests cache misses.
*/

void function1(long *arr, long sI, long sJ);
void function2(long *arr, long sI, long sJ);
void function3(long *arr, long sI, long sJ);
int main(int argc, char **argv)
{
  if (argc < 3){
    printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
    return 1;
  }
  long sI = atoi(argv[1]);
  long sJ = atoi(argv[2]);

  printf("Operating on matrix of size %ld by %ld\n", sI, sJ);

  long *arr = new long[sI*sJ]; // double array.

  // option 1
  // for (long i=0; i < sI; ++i)
    // for (long j=0; j < sJ; ++j)
      // arr[(i * (sJ)) + j ] = i;
 function1(arr, sI, sJ);
  // option 2
  // for (long i=0; i < sI; ++i)
  //   for (long j=0; j < sJ; ++j)
  //     arr[(j * (sI)) + i ] = i;
 function2(arr, sI, sJ);
  // option 3
  // for (int i=0; i < sI*sJ; ++i) arr[i] = i;
 function3(arr, sI, sJ);
  printf("%ld\n", arr[0]);
  
  return 0;
}

void function1(long *arr, long sI, long sJ){
  for (long i=0; i < sI; ++i)
    for (long j=0; j < sJ; ++j)
      arr[(i * (sJ)) + j ] = i;}
void function2(long *arr, long sI, long sJ){
  for (long i=0; i < sI; ++i)
    for (long j=0; j < sJ; ++j)
      arr[(j * (sI)) + i ] = i;}

void function3(long *arr, long sI, long sJ){
  for (int i=0; i < sI*sJ; ++i){
    arr[i] = i;}
}
