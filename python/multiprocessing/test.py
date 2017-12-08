#!/usr/bin/env python

import multiprocessing as mp
import sys
import time
from subprocess import check_call, STDOUT
import math


def foo(n):
    startT = time.time()

    total = 0
    for x in xrange(n):
        total += math.factorial(x)


    endT = time.time()
    print("{} to {} = {:.3f} seconds".format(startT, endT, endT - startT))



def run_mp(task):
    print("run task {}".format(task))
    p = mp.Process(target=foo, args=(2000 * task,))
    p.start()


def main(args):
    run_mp(1)
    run_mp(2)

if __name__ == "__main__":
    main(sys.argv[1:])
