#!/usr/bin/env python

import multiprocessing as mp
import sys
import time
from subprocess import check_call, STDOUT
import math


from multiprocessing import Process, Value, Array


def foo(n, taskid, shared_timing_arr):
    startT = time.time()

    total = 0
    for x in xrange(n):
        total += math.factorial(x)

    endT = time.time()
    #print("{} to {} = {:.3f} seconds".format(startT, endT, endT - startT))
    shared_timing_arr[taskid * 2] = startT 
    shared_timing_arr[taskid * 2 + 1] = endT



def run_mp(func_param, taskid, shared_timing_arr):
    #print("run task {}".format(taskid))
    p = mp.Process(target=foo, args=(2000 * func_param, taskid, shared_timing_arr))
    p.start()
    p.join()


def main(args):

    import numpy as np

    timing_arr = Array('d', np.zeros(10), lock=False)
    #timing_arr = Array('d', np.zeros(10), lock=True)

    print timing_arr[:]
    print timing_arr[0]
    print timing_arr[1]

    run_mp(1, 0, timing_arr)
    print("task 0: start {} to end {} = {:.3f}".format(timing_arr[0], 
        timing_arr[1], timing_arr[1] - timing_arr[0]))

    time.sleep(1)

    run_mp(2, 1, timing_arr)
    print("task 1: start {} to end {} = {:.3f}".format(timing_arr[2], 
        timing_arr[3], timing_arr[3] - timing_arr[2]))


    print "task 1 is delayed " + str(timing_arr[2] - timing_arr[0]) 

if __name__ == "__main__":
    main(sys.argv[1:])
