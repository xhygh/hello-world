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
        
        
        # approach3
