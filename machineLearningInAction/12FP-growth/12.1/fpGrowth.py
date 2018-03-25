#coding: utf-8

class treeNode:
    def __init__(self, nameValue, numOccur, parentNode):
        self.name = nameValue
        self.count = numOccur
        self.nodeLink = None
        self.parent = parentNode
        self.children = {}

    def inc(self, numOccur):
        '''增加结点下发生次数'''
        self.count += numOccur

    def disp(self, ind = 1):
        '''打印树结构'''
        print ' '*ind, self.name, ' ', self.count
        for child in self.children.values():
            child.disp(ind + 1)


#############################################
# 树结点构造
def createTree(dataSet, minSup = 1):
    '''
    function: 创建FP树
    @params: 
        dataSet: 数据集-字典结构{事务集：次数}
        minSup: 最小支持度
    @return: 
        retTree: FP树的实例
        headerTable: 头指针表
    '''
    # 头指针表
    headerTable = {}
    for trans in dataSet:
        for item in trans:
            headerTable[item] = headerTable.get(item, 0) + dataSet[trans]
            # 这个dataSet[trans]难道是表示这个trans事务的重复个数么？

    # 删除不满足最小支持度的单项集
    for k in headerTable.keys():
        if headerTable[k] < minSup:
            del(headerTable[k])

    # 所有一项集的元素
    freqItemSet = set(headerTable.keys())

    if len(freqItemSet) == 0: return None, None

    for k in headerTable:
        headerTable[k] = [headerTable[k], None]

    retTree = treeNode('Null Set', 1, None)

    for tranSet, count in dataSet.items():
        localD = {}
        for item in tranSet:
            if item in freqItemSet:
                localD[item] = headerTable[item][0]
            if len(localD) > 0:
                # 利用列表解析式进行的这个排序很有意思
                orderedItems = [v[0] for v in sorted(localD.items(), key=lambda p: p[1], reverse=True)]
                updateTree(orderedItems, retTree, headerTable, count)

    return retTree, headerTable;

def updateTree(items, inTree, headerTable, count):
    '''
    function:
    @params:
        items: 排序之后的事务中items列表
        inTree: 树结点
        headerTable: 头指针表
        count: 同一事务的数量
    @return:
        无返回项，只是不断的更新FP树结构和headerTable头节点链表
    '''
    if items[0] in inTree.children:
        inTree.children[items[0]].inc(count)
    else:
        inTree.children[items[0]] = treeNode(items[0], count, inTree)
        # 当还items[0]元素还是第一次出现，没有前面的头指针
        if headerTable[items[0]][1] == None:
            headerTable[items[0]][1] = inTree.children[items[0]]
        else:
            updateHeader(headerTable[items[0]][1], inTree.children[items[0]])

    # 递归来将事务中的items全部都入树
    if len(items) > 1:
        updateTree(items[1::], inTree.children[items[0]], headerTable, count)

def updateHeader(nodeToTest, targetNode):
    while (nodeToTest.nodeLink != None):
        nodeToTest = nodeToTest.nodeLink
    nodeToTest.nodeLink = targetNode

########################################


########################################
# 初始化数据
def loadSimpDat():
    '''原始数据集'''
    simpDat = [ ['r', 'z', 'h', 'j', 'p'],
                ['z', 'y', 'x', 'w', 'v', 'u', 't', 's'],
                ['z'],
                ['r', 'x', 'n' , 'o', 's'],
                ['y', 'r', 'x', 'z', 'q', 't', 'p'],
                ['y', 'z', 'x', 'e', 'q', 's', 't', 'm'] ]
    return simpDat

def createInitSet(dataSet):
    retDict = {}
    for trans in dataSet:
        retDict[frozenset(trans)] = 1
    return retDict
########################################


########################################
# FP树的频繁挖掘
def ascendTree(leafNode, prefixPath):
    '''
    function: 返回前缀结点列表
    @params:
        leafNode: 叶子结点
        prefixPath: 递归求得前缀路径
    @return:
        prefixPath列表数据
    '''
    if leafNode.parent != None:
        prefixPath.append(leafNode.name)
        ascendTree(leafNode.parent, prefixPath)

def findPrefixPath(basePat, treeNode):
    '''
    function: 输出条件模式基
    @params:
        basePat: 单项基础模式基
        treeNode: 
    @return：
        条件模式基字典数据
    '''
    condPats = {}
    while treeNode != None:
        prefixPath = []
        ascendTree(treeNode, prefixPath)
        if len(prefixPath) > 1:
            condPats[frozenset(prefixPath[1:])] = treeNode.count
        treeNode = treeNode.nodeLink
    return condPats

########################################


########################################
# 创建条件FP树
def mineTree(inTree, headerTable, minSup, preFix, freqItemList):
    '''
    function:
    @params:
        inTree: 
        headerTable:
        minSup:
        preFix:
        freqItemList:
    @return:

    '''
    bigL = [v[0] for v in sorted(headerTable.items(),
                                 key = lambda p: p[1])]
    for basePat in bigL:
        newFreqSet = preFix.copy()
        newFreqSet.add(basePat)
        freqItemList.append(newFreqSet)
        condPattBases = findPrefixPath(basepat, headerTable[basePat][1])
        myCondTree, myHead = createTree(condPattBases, minSup)

        if myHead != None:
            mineTree(myCondTree, myHead, minSup, newFreqSet, freqItemList)



if __name__ == '__main__':
    simpDat = loadSimpDat()
    initSet = createInitSet(simpDat)
    myFPtree, myHeaderTab = fpGrowth.createTree(initSet, 3)

    myFPtree.disp()

