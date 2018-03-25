from numpy import *
import operator

def createDateSet():
    """
    

    """
    group = array([[1.0, 1.1], [1.0, 1.0], [0, 0], [0, 0.1]])
    labels = ['A', 'A', 'B', 'B']
    return group, labels

def classify0(inX, dataSet, labels, k):
    """
    parameters:
        inX: 
        dataSet: features value (2d array)
        labels: labels value list
        k:
    """
    dataSetSize = dataSet.shape[0]
    # change the caculation into matrix operation
    diffMat = tile(inX, (dataSetSize, 1)) - dataSet
    
    # get the distance 1-d array
    sqDiffMat = diffMat**2
    sqDistances = sqDiffMat.sum(axis = 1)
    distance = sqDistances**0.5
    sortedDistIndicies = distance.argsort()

    classCount = {}
    for i in range(k):
        voteIlabel = labels[sortedDistIndicies[i]]
        classCount[voteIlabel] = classCount.get(voteIlabel, 0) + 1
    	
	# sorted combined with operation.itemgetter to get sorted dict value
	sortedClassCount = sorted(classCount.iteritems(),
        			  key = operator.itemgetter(1), 
				  reverse = True)
    return sortedClassCount[0][0]

def file2matrix(filename):
    fr = open(filename)
    arrayOLines = fr.readlines()
    numberOfLines = len(arrayOLines)
    
    returnMat = zeros((numberOfLines, 3))

    classLabelVector = []
    index = 0

    for line in arrayOLines:
        line = line.strip()
        # line = line.strip().split('\r')[0]
	# print line
	listFromLine = line.split('\t')
	returnMat[index,:] = listFromLine[0:3]
	classLabelVector.append(int(listFromLine[-1]))
	index += 1

    return returnMat, classLabelVector

def autoNorm(dataSet):
    minVals = dataSet.min(0)
    maxVals = dataSet.max(0)
    ranges = maxVals - minVals
    normDataSet = zeros(shape(dataSet))
    m = dataSet.shape[0]
    normDataSet = dataSet - tile(minVals, (m, 1))
    normDataSet = normDataSet/tile(ranges, (m, 1))

    # numpy possess a great matrix operation

    return normDataSet, ranges, minVals

def dataingClassTest():
    hoRatio = 0.10
    datingDataMat, datingLabels = file2matrix('C:/Users/29628/Desktop/githubFile/Algorithm/machineLearningInAction/02KNN/datingTestSet.txt')
    normMat, ranges, minVals = autoNorm(datingDataMat)
    m = normMat.shape[0]
    numTestVecs = int(m * hoRatio)
    errorCount = 0.0
    for i in range(numTestVecs):
        classifierResult = classify0(normMat[i,:], normMat[numTestVecs:m,:], \
                                     datingLabels[numTestVecs:m], 12)
        print "the classifier came back with: %d, the real answer is: %d " \
                        % (classifierResult, datingLabels[i])
        if(classifierResult != datingLabels[i]): errorCount += 1.0

    print "the total error rate is: %f" %(errorCount/float(numTestVecs))

def classifyPerson():
    resultList = ['not at all', 'in small doses', 'in large doses']
    percentTats = float(raw_input(\
                        "percentage of time spent playing video game? "))
    ffMiles = float(raw_input(\
                        "frequent flier miles earned per year? "))
    iceCream = float(raw_input(\
                        "liters of ice cream consumed per year? "))

    datingDataMat, datingLabels = file2matrix('./datingTestSet.txt')
    normMat, ranges, minVals = autoNorm(datingDataMat)
    inArr = array([ffMiles, percentTats, iceCream])
    classifierResult = classify0((inArr - minVals)/ranges, normMat, datingLabels, 3)
    print 'You will probably like this person: ', \
            resultList[classifierResult - 1]


if __name__ == '__main__':
    # Test dataset
    group, labels = createDateSet()
    print group
    print labels
    print '#' * 30

    # Test classify0 function
    print classify0([0, 0], group, labels, 3)

    print '#' + '-'*30 + '#'
    filename = 'C:/Users/29628/Desktop/githubFile/Algorithm/machineLearningInAction/02KNN/datingTestSet.txt'
    returnMat, classLabelVector = file2matrix(filename)
    
    print returnMat
    print classLabelVector

    print '#' + '-'*30 + '#'

    import matplotlib
    import matplotlib.pyplot as plt

    fig = plt.figure()
    ax = fig.add_subplot(111)
    # ax.scatter(returnMat[:,1], returnMat[:,2])
    # plt.show()

    # third parameters is the 3th data, forth parameters is the color
    ax.scatter(returnMat[:,0], returnMat[:,2], 
               15.0 * array(classLabelVector), 15.0 * array(classLabelVector))
    plt.show()


    print '#' + '-' * 30 + '#'
    normMat, ranges, minVals = autoNorm(returnMat)

    print normMat

    print '#' + '-' * 30 + '#'

    dataingClassTest()

    classifyPerson()





