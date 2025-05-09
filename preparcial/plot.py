import matplotlib.pyplot as plt
import numpy as np

t, w  = np.loadtxt("derivatives.txt", unpack=True)


plt.scatter(t, w, color='blue', label='Puntos (x, y)')
plt.title('Gráfico de puntos desde archivo')
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.legend()
plt.grid(True)
plt.show()