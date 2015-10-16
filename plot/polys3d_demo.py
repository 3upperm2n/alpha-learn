from mpl_toolkits.mplot3d import Axes3D
from matplotlib.collections import PolyCollection
from matplotlib.colors import colorConverter
import matplotlib.pyplot as plt
import numpy as np

#fig = plt.figure()
#ax = fig.gca(projection='3d')
#
#cc = lambda arg: colorConverter.to_rgba(arg, alpha=0.6)
#
#xs = np.arange(0, 10, 0.4)
#verts = []
#zs = [0.0, 1.0, 2.0, 3.0]
#for z in zs:
#    ys = np.random.rand(len(xs))
#    ys[0], ys[-1] = 0, 0
#    verts.append(list(zip(xs, ys)))
#
#poly = PolyCollection(verts, facecolors = [cc('r'), cc('g'), cc('b'),
#                                           cc('y')])
#poly.set_alpha(0.7)
#ax.add_collection3d(poly, zs=zs, zdir='y')
#
#ax.set_xlabel('X')
#ax.set_xlim3d(0, 10)
#ax.set_ylabel('Y')
#ax.set_ylim3d(-1, 4)
#ax.set_zlabel('Z')
##ax.set_zlim3d(0, 1)
#
#plt.show()


fig = plt.figure()
ax = fig.gca(projection='3d')

cc = lambda arg: colorConverter.to_rgba(arg, alpha=0.6)

#xs = np.arange(0, 10, 0.4)
xs = np.array([0.0, 1.0, 2.0, 3.0, 4.0 ,5.0, 6.0])

verts = []
zs = [0.0, 1.0, 2.0]

cnt = 0

for z in zs:
    print cnt
    if cnt == 0:
        ys = np.array([0, 2031.2, 1602.2, 1574.8, 1658.8, 2205, 0])
    elif cnt == 1:
        ys = np.array([0, 2269.8, 1330.2, 1336.2, 1450.6, 2516.8, 0])
    else:
        ys = np.array([0, 1782.2, 1798.2, 1791.2, 1802.4, 1872.2, 0])
#    ys = np.random.rand(len(xs))
#    ys[0], ys[-1] = 0, 0
    verts.append(list(zip(xs, ys)))
    cnt = cnt + 1
        


poly = PolyCollection(verts, facecolors = [cc('r'), cc('g'), cc('b')])
poly.set_alpha(0.7)
ax.add_collection3d(poly, zs=zs, zdir='y')

ax.set_xlabel('X')
ax.set_xlim3d(0, 6)

ax.set_ylabel('Y')
ax.set_ylim3d(-1, 3)

ax.set_zlabel('Z')
ax.set_zlim3d(0, 3000)

plt.show()
