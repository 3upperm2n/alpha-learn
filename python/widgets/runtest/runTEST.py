#!/usr/bin/env python

__author__ = 'Leiming Yu'

import sys
import subprocess # run commands
import argparse # parse arguments
import re

def save2file(cmd, logfile):
    p = subprocess.Popen(cmd, shell=True, universal_newlines=True, stdout=logfile)
    ret_code = p.wait()
    logfile.flush()
    return ret_code

#-------------------------------
def main():

	parser = argparse.ArgumentParser(description='Run program N times to evaluate performance.')
	parser.add_argument("prog", help='executable program')
	parser.add_argument("-a", "--arg", help="program arguments") # optional
	parser.add_argument("-N", help='number of repetition', type=int) # optional

	args = parser.parse_args()

	prog     = args.prog
	prog_arg = args.arg
	N        = args.N

	f = file('out.txt', 'w') # create a file
	if prog_arg == None:
		for i in range(N):
			subprocess.call(['./'+prog], stdout=f)
	else:
		for i in range(N):
			subprocess.call(['./'+prog,prog_arg], stdout=f)

	f.close()
		
	# read file and save runtime 
	elapsedTime = []
	f = open('out.txt','r')
	regex = re.compile(r'\(s\)') # line with (s)

	for line in f:
		if regex.search(line):
			fields = line.split(" ")
			elapsedTime.append(float(fields[2]))

	f.close()

	# sort and find 
	#print elapsedTime
	print  '\nBest record = ' + str(min(elapsedTime)) + ' (s)\n'



#-------------------------------
if __name__ == "__main__":
    main()
