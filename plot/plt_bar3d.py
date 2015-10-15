#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
#  File:        plot_2.py
#  Author:      Leiming Yu <ylm@ece.neu.edu>
#  Copyright    2015 
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  

import sys
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

xs = [1, 2, 3, 4, 5]

for c, z, i in zip(['r', 'g', 'b'], [1, 2, 3], [0, 1, 2]):

    if i == 0:
        ys = [2031.2, 1602.2, 1574.8, 1658.8, 2205]
    elif i == 1:
        ys = [2269.8, 1330.2, 1336.2, 1450.6, 2516.8]
    else: 
        ys = [1782.2, 1798.2, 1791.2, 1802.4, 1872.2]
        

    # You can provide either a single color or an array. To demonstrate this,
    # the first bar of each set will be colored cyan.
    cs = [c] * len(xs)

    ax.bar(xs, ys, zs=z, zdir='y', color=cs, alpha=0.8)



#labels = [item.get_text() for item in ax.get_xticklabels()]
#print labels
#
#labels = [item.get_text() for item in ax.get_yticklabels()]
#print labels
#
#labels = [item.get_text() for item in ax.get_zticklabels()]
#print labels

ax.set_xticklabels(['32','64','128', '256', '512'])
ax.set_yticklabels(['16384','','9600', '', '6400'])


ax.set_xlabel('Threads Per Block')
ax.set_ylabel('Total Threads')
ax.set_zlabel('Kernel Execution Time (ms)')


plt.show()















#    
#x = np.array([[32, 64, 128, 256, 512], \
#[32, 64, 128, 256, 512], \
#[32, 64, 128, 256, 512]], np.int)
#
#
#y = np.array([[2031.2, 1602.2, 1574.8, 1658.8, 2205], \
#    [2269.8, 1330.2, 1336.2, 1450.6, 2516.8], \
#    [1782.2, 1798.2, 1791.2, 1802.4, 1872.2]], np.float)
#
#
##    z = np.array([16384, 9600, 6400])
##    c = np.array(['r', 'g', 'b'])
#
#    
#fig = plt.figure()
#ax = fig.add_subplot(111, projection='3d')
#
#for c, z, i in zip(['r', 'g', 'b'], [16384, 9600, 6400], [0, 1, 2]):
##   xs = x[[i], :]
#    xs = x[i]
#    ys = y[i]
##   print ys
##   print ys.dtype
##   print type(ys)
#    cs = [c] * len(xs)
#    print xs
#    print ys
#    print cs
#
#    ax.bar(xs, ys, zs=z, zdir='y', color=cs, alpha=0.8)
#
#ax.set_xlabel('X')
#ax.set_ylabel('Y')
#ax.set_zlabel('Z')
#
#plt.show()   
