"""
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
"""
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        opt = collections.defaultdict(lambda:1)
        opt[1] = 1
        for i in range(2,n+1):
            opt[i] = opt[i-1] + opt[i-2]
        return opt[n]
        
