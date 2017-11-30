#!/usr/bin/env python

import sched,time
import sys

s = sched.scheduler(time.time,time.sleep)


def func():
    print  'run func()\n'

def test1():
    s.enter(2,1,func, ())
    s.run()




def job():
    print "I am working!"

def test2():
    schedule.every(1).seconds.do(job)

    #max_jobs, count = 10, 0
    while True:
        schedule.run_pending()   # works
        #schedule.run_all()   # not running at the fixed interval
        #count = count + 1
        #if  count == max_jobs:
        #    print "\nAll done!"
        #    break

def tests():
    test1()
    #test2()

    return 0

if __name__ == "__main__":
    #print sys.path
    tests()
