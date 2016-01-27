from math import log
import operator


def createDataSet():
    dataSet = [[1, 1, 'yes'],
               [1, 1, 'yes'],
               [1, 0, 'no'],
               [0, 1, 'no'],
               [0, 1, 'no']]
    labels = ['no surfacing','flippers']
    #change to discrete values
    return dataSet, labels

def createDataSet1():
#    dataSet = [['yes', 'yes', 'yes'],
#               ['yes', 'yes', 'yes'],
#               ['yes', 'no', 'no'],
#               ['no', 'yes', 'no'],
#               ['no', 'yes', 'no']]
    dataSet = [[1, 1, 'yes'],
               [1, 1, 'yes'],
               [1, 0, 'no'],
               [0, 1, 'no'],
               [0, 1, 'no']]
    labels = ['no surfacing','flippers','fish']
    #change to discrete values
    return dataSet, labels
    

def calcShannonEnt(dataSet):
    numEntries = len(dataSet)
#    print numEntries
    
#    dicitionary
    labelCounts = {}
    
    #the the number of unique elements and their occurance
    for featVec in dataSet: 
#        print the last label
        currentLabel = featVec[-1]
#        print currentLabel        
        if currentLabel not in labelCounts.keys(): 
            labelCounts[currentLabel] = 0
        
        labelCounts[currentLabel] += 1
    
#    print labelCounts
    
    shannonEnt = 0.0
    
    for key in labelCounts:
#        print labelCounts[key]
        prob = float(labelCounts[key])/numEntries
        shannonEnt -= prob * log(prob,2) #log base 2
    return shannonEnt


def splitDataSet(dataSet, axis, value):
    retDataSet = []
    for featVec in dataSet:
#        print featVec
        if featVec[axis] == value:
#            print featVec
#            print featVec[axis]
            reducedFeatVec = featVec[:axis]     #chop out axis used for splitting
#            print reducedFeatVec
            reducedFeatVec.extend(featVec[axis+1:])
#            print reducedFeatVec
            retDataSet.append(reducedFeatVec)
    return retDataSet

def chooseBestFeatureToSplit(dataSet):
    numFeatures = len(dataSet[0]) - 1      #the last column is used for the labels
#    print dataSet[0]
    
    baseEntropy = calcShannonEnt(dataSet)
    
    bestInfoGain = 0.0; bestFeature = -1
        
    #iterate over all the features
    for i in range(numFeatures):        
    #create a list of all the examples of this feature
        featList = [example[i] for example in dataSet]

#        print featList        
        
        uniqueVals = set(featList)       #get a set of unique values

#        print uniqueVals        
        
        newEntropy = 0.0
        
        for value in uniqueVals:
            subDataSet = splitDataSet(dataSet, i, value)
            prob = len(subDataSet)/float(len(dataSet))
            newEntropy += prob * calcShannonEnt(subDataSet) 
#        print newEntropy
        
        infoGain = baseEntropy - newEntropy     #calculate the info gain; ie reduction in entropy
#        print infoGain        
        
        if (infoGain > bestInfoGain):       #compare this to the best gain so far
            bestInfoGain = infoGain         #if better than current best, set to best
            bestFeature = i
    return bestFeature                      #returns an integer




def majorityCnt(classList):
    classCount={}
    for vote in classList:
        if vote not in classCount.keys(): classCount[vote] = 0
        classCount[vote] += 1
    sortedClassCount = sorted(classCount.iteritems(), 
                              key=operator.itemgetter(1), reverse=True)
    return sortedClassCount[0][0]
    
    
    
def createTree(dataSet,labels):
    classList = [example[-1] for example in dataSet]

#    print classList  
#    print   len(classList), classList[0]
    
    #stop splitting when all of the classes are equal
    if classList.count(classList[0]) == len(classList): 
        return classList[0]

#   stop splitting when there are no more features in dataSet
    if len(dataSet[0]) == 1: 
#        print majorityCnt(classList)
        return majorityCnt(classList)


    bestFeat = chooseBestFeatureToSplit(dataSet)    
    
    bestFeatLabel = labels[bestFeat]
    
    myTree = {bestFeatLabel:{}}
    del(labels[bestFeat])
    
    featValues = [example[bestFeat] for example in dataSet]
    uniqueVals = set(featValues)
    
    for value in uniqueVals:
        #copy all of labels, so trees don't mess up existing labels
        subLabels = labels[:]       
        myTree[bestFeatLabel][value] = createTree(splitDataSet(dataSet, bestFeat, value),subLabels)
    return myTree    

    
    
    

