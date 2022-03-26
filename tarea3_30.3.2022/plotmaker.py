#!/usr/bin/env python
# coding: utf-
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
#import the file
df = pd.read_csv(r'data.txt', sep="\t")
#following https://moonbooks.org/Articles/How-to-put-the-y-axis-in-logarithmic-scale-with-Matplotlib-/
plt.scatter(df['n'], df['gamma_n'])
plt.title('$\gamma_n$ vs n')
plt.ylabel('$\gamma_n$')
plt.xlabel('$n$')
#plt.yscale('log')
#plt.xscale('log')
plt.grid(True, linestyle='--')
plt.savefig('gamma_vs_n.pdf', format='pdf')

