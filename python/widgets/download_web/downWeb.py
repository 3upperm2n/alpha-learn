#!/usr/bin/env python

__author__ = 'Leiming Yu'

import sys
import subprocess

#-------------------------------
def main():
	total_args = len(sys.argv)
	cmdargs = str(sys.argv)
	#print 'Number of arguments:', len(sys.argv), 'arguments.'
	#print 'Argument List:', str(sys.argv)	

	url = str(sys.argv[1])
	print 'website : %s' % url 

	subprocess.call(['wget','-r','-nH','--no-parent',url])

#-------------------------------
if __name__ == "__main__":
    main()
