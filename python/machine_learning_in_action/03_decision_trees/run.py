#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
#  File:        xxx.py
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
import trees

def main(argv):
    
#------------------------------------------------------------------------------
#    create
#------------------------------------------------------------------------------
    myDat, labels = trees.createDataSet() 
#    print myDat
#    print labels
    
#------------------------------------------------------------------------------
#    entrophy
#------------------------------------------------------------------------------
    result = trees.calcShannonEnt(myDat)
#    print result
    
#    print myDat
    
#    print 'mix more with the dataset'
#    #add more complex to the data
#    myDat[0][-1] = 'maybe'
#    print myDat
#    
#    print trees.calcShannonEnt(myDat)

#------------------------------------------------------------------------------
#    split data
#------------------------------------------------------------------------------
#    print trees.splitDataSet(myDat, 0,1)
    
#    print trees.splitDataSet(myDat, 0,0)
        
#------------------------------------------------------------------------------
#    split data
#------------------------------------------------------------------------------    
#    print trees.chooseBestFeatureToSplit(myDat)
    
#------------------------------------------------------------------------------
#    create trees
#------------------------------------------------------------------------------ 
    
    myDat, labels = trees.createDataSet1() 
#    print myDat   
#    print labels
    
    myTree = trees.createTree(myDat, labels)
    print myTree
    
    
    return 0


if __name__ == '__main__':
    main(sys.argv[1:])
