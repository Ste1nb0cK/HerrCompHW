#!/usr/bin/env python
# coding: utf-
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
#import the file
df2 = pd.read_csv(r'pdf2.txt', sep="\t")
df1 = pd.read_csv(r'pdf1.txt', sep="\t")
df5 = pd.read_csv(r'pdf5.txt', sep="\t")
#following https://moonbooks.org/Articles/How-to-put-the-y-axis-in-logarithmic-scale-with-Matplotlib-/
#to matplotlib figures.
#Here is a very interesting example on how to add latex annotations
#https://matplotlib.org/3.5.1/gallery/text_labels_and_annotations/tex_demo.html
plt.scatter(df1['x'], df1['rho(x)'], label='1')
plt.scatter(df2['x'], df2['rho(x)'], label='2')
plt.scatter(df5['x'], df5['rho(x)'], label='5')
plt.title('pdf')
plt.ylabel(r"$\rho(x)$")
plt.xlabel("$x$")
#plt.yscale('log')
#plt.xscale('log')
plt.legend(title="Semilla")
plt.grid(True, linestyle='--')
plt.savefig('pdf.pdf', format='pdf')
