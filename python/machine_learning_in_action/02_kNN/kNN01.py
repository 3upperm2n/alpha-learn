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
from numpy import * 
import operator

def createDataSet():
    group = array([[1.0,1.1],[1.0,1.0],[0,0],[0,0.1]]) 
    labels = ['A','A','B','B'] 
    return group, labels

def classify0(inX, dataSet, labels, k): 
#    the number of rows
    dataSetSize = dataSet.shape[0]
# print dataSetSize

#   replicate input X by number of rows, and calculate the difference 
    diffMat = tile(inX, (dataSetSize,1)) - dataSet 
    
#    squre distance
    sqDiffMat = diffMat**2    
    
#    summation along the rows, we know the dist from input to the dataset
    sqDistances = sqDiffMat.sum(axis=1)


#   take the square root    
    distances = sqDistances**0.5
#    print distances    

#   return the indice that could sort the array, default as increasing order    
    sortedDistIndicies = distances.argsort()
#    print sortedDistIndicies
    
#    start an dictionary
    classCount = {}
#    print type(classCount)

#   check the 1st k neighbours
    for i in range(k):
        voteIlabel = labels[sortedDistIndicies[i]]
#        print  voteIlabel
        
#       accumulate the counts for each k groups
        classCount[voteIlabel] = classCount.get(voteIlabel,0) + 1
#        print classCount
        
#       sort the classCount        
    sortedClassCount = sorted(classCount.iteritems(), key=operator.itemgetter(1), reverse=True)
#    print sortedClassCount
    
    return sortedClassCount[0] [0]

#Voting with lowest
#for i in range(k):
#k distances
# 
#Sort
#return