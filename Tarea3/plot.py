import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
a, b, n, tr, etr, sm, esm, rt, ert, rs, ers  = np.loadtxt("integrals.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(n, etr, '-o', label='error trapezoid')
ax.plot(n, esm, '-s', label='error simpson')
ax.plot(n, ert, '-*', label='error richardson trapezoid')
ax.plot(n, ers, '-*', label='error richardson simpson')
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('$n$')
ax.set_ylabel('error')
ax.legend()
fig.savefig('deriv.pdf')