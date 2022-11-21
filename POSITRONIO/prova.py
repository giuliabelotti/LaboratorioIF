import numpy as np
import pylab
from matplotlib import pyplot as plt
from scipy.optimize import curve_fit

def f(t,b,c):
    return np.log(t + b) + c

t,V = pylab.loadtxt("PlotData.txt", unpack=True)
dV = V/100
m = min(V)
s = 0
for i in range(len(V)): #individua il minimo
    if (V[i]==m):
        k = i
        break

y = np.zeros(len(V)-k)
dy = np.zeros(len(V)-k)

for i in range(len(V)-k): #riempie y con i valori di V dal minimo in poi
    y[i] = V[k + i]
    dy[i] = dV[k + i]

x = np.linspace(0, len(t)-k, len(t)-k)

plt.errorbar(x,y, dy , None, ".")
for i in range(len(y)-1): #calcola l'integrale facendo la somma delle aree di
#rettangoli e triangoli
    s = s + ((y[i] * 1) + (y[i+1] - y[i]) * 0.5)
print(s)

plt.show()
