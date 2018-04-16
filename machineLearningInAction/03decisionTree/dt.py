#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Mon Apr 16 13:53:47 2018

@author: femap
"""
import math

def calcShannonEnt(dataSet):
    numEntries = len(dataSet)
    labelCounts = {}
    for featVec in dataSet:
        currentLabel = featVec[-1]
        if currentLabel not in labelCounts.keys():
            labelCounts[currentLabel] = 0
        labelCounts[currentLabel] += 1
                   
    shannonEnt = 0.0
    for key in labelCounts:
        prob = float(labelCounts[key]) / numEntries
        shannonEnt -= prob * math.log(prob, 2)
    
    return shannonEnt

def splitDataSet(dataSet, index, value):
    retDataSet = []
    for featVec in dataSet:
        if featVec[index] == value:
            reducedFeatVec = featVec[:index]
            reducedFeatVec.extend(featVec[index+1:])
            retDataSet.append(reducedFeatVec)
    return retDataSet

def chooseBestFeatureToSplit(dataSet):
    numFeatures = len(dataSet[0]) - 1
    baseEntropy = calcShannonEnt(dataSet)

    bestInfoGain, bestFeature = 0.0, -1
    
    for i in range(numFeatures):
        featList = [example[i] for example in dataSet]
        
        uniqueVals = set(featList)
        
        newEntropy = 0.0
        
        for value in uniqueVals:
            subDataSet = splitDataSet(dataSet, i, value)
            
            prob = len(subDataSet) / float(len(dataSet))
        
            newEntropy += prob * calcShannonEnt(subDataSet)
        
        infoGain = baseEntropy - newEntropy
        print 'infoGain=', infoGain, 'bestFeature=', i, baseEntropy, newEntropy
        
        if infoGain > bestInfoGain:
            bestInfoGain = infoGain
            bestFeature  = i
            
    return bestFeature
        

def createDataSet():
    dataSet = [[1, 1, 'yes'],
               [1, 1, 'yes'],
               [1, 0, 'no'],
               [0, 1, 'no'],
               [0, 1, 'no']]
    lables = ['no surfacing', 'flippers']
    return dataSet, labels
    
def createTree(dataSet, labels):
    classList = [example[-1] for example in dataSet]
    if classList.count(classList[0]) == len(classList):
        return classList[0]
    if len(dataSet[0] == 1):
        return majorityCnt(classList)
    
    bestFeat = chooseBestFeatureToSplit(dataSet)
    
    bestFeatLabel = labels[bestFeat]
    myTree = {bestFeatLable: {}}
    
    del(labels[bestFeat])
    
    

def classify(inputTree, featLabels, testVec):
    """Key point is the datastruct of inputTree"""
    firstStr = inputTree.keys()[0]
    secondDict = inputTree[firstStr]
    featIndex = featLabels.index(firstStr)
    
    key = testVec[featIndex]
    valueOfFeat = secondDict[key]
    print '+++', firstStr, 'xxx', secondDict, '---', key, '>>>', valueOfFeat
    
    if isinstance(valueOfFeat, dict):
        classLabel = classify(valueOfFeat, featLabels, testVec)
    else:
        lacssLabel = valueOfFeat
    return classLabel