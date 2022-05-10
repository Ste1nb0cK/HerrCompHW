#!/bin/bash
cores=8
for size in {1..10000..100};
do
    touch results_$cores.txt
    OMP_NUM_THREADS=$cores a.out $size  >> results_$cores.txt
done
