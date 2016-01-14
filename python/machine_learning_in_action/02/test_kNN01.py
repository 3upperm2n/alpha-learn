#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  File:        xxx.py
#  Author:      leiming <ylm@ece.neu.edu>
#  Copyright    2014 
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
import kNN01

def main(argv):
    group,labels = kNN01.createDataSet()
    
    result = kNN01.classify0([0, 0], group, labels, 3)    
    print result
    
    return 0


if __name__ == '__main__':
    main(sys.argv[1:])
