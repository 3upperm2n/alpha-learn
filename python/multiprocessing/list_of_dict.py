#!/usr/bin/env python
import multiprocessing
from multiprocessing import Manager

manager = Manager()

# create a list proxy and append a mutable object (a dictionary)
lproxy = manager.list()
lproxy.append({})
print lproxy[0]

# now mutate the dictionary
d = lproxy[0]
d['a'] = 1
d['b'] = 2
# at this point, the changes to d are not yet synced, but by
# reassigning the dictionary, the proxy is notified of the change
lproxy[0] = d

print lproxy[0]





manyproxy = [manager.list() for i in xrange(2)]
print manyproxy
print manyproxy[0]

#for item in manyproxy:
#    item = item.append({})

for i in xrange(len(manyproxy)):
    lp = manyproxy[i]
    lp.append({})
    #manyproxy[i] = manyproxy[i].append({})
print manyproxy
print manyproxy[0]



for i in xrange(len(manyproxy)):
    d = manyproxy[i][0]
    d['yu'] = 1 + i 
    d['chen'] = 2 + i
    manyproxy[i] = d

print manyproxy
print manyproxy[0]
print manyproxy[1]
