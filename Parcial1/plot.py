import matplotlib.pyplot as plt
import numpy as np

# read data
x, h, fr, cr, fe, ce, rfe, rce, rfe3, rce3 = np.loadtxt("richardson.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(h, fe, '-o', label='error forward')
ax.plot(h, ce, '-s', label='error central')
ax.plot(h, rfe, '-*', label='error richardson forward')
ax.plot(h, rce, '-*', label='error richardson central')
ax.plot(h, rfe3, '-o', label='error richardson forward x3')
ax.plot(h, rce3, '-o', label='error richardson central x3')
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('$h$')
ax.set_ylabel('error')
ax.legend()
fig.savefig('deriv.pdf')