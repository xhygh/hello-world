"""
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
"""

class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        # approach1
        if numRows == 0: return[]
        results = [[1]]
        for i in range(1, numRows):
            tmp=[]
            for j in range(i+1):
                ################
                #if j==0 or j==i:
                #    tmp.append(1)
                #else:
                #    tmp.append(results[i-1][j-1]+results[i-1][j])
                ################
                tmp.append((results[i-1][j-1] if j>0 else 0)+(results[i-1][j] if j<i else 0))
            results.append(tmp)
        return results
        
        # approach2
        # 可以先生成每行形式，在替换中间的元素
        res = []
        for i in range(0,numRows):
            res.append([1]*(i+1))
            for j in range(1,i):
                res[i][j] = res[i-1][j-1] + res[i-1][j]
        return res
        # approach3
        # 每行两边是1，res[i][j]=res[i-1][j-1]+res[i-1][j],也可以理解为i-1行与其副本相错一个位置相加的结果。
        # 1 3 3 1 0 +
        # 0 1 3 3 1
        #=1 4 6 4 1
        # 因为是对称的，所以正反相加就可以
        if numRows == 0: return[]
        res=[[1]]
        for i in range(1,numRows):
            res += [map(lambda x,y:x+y,res[-1]+[0],[0]+res[-1])]
        return res
