"""
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
"""

'''
>>> import math
>>> n=243
>>> tmp = math.log(n, 3)
>>> tmp
4.999999999999999
>>> math.log10(n) / math.log10(3)
5.0

'''

class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if not n or n<0: return False
        #tmp = math.log(n,3)可能有n=243时，tmp=4.999999999,如此，int(tmp)=4
        tmp = math.log10(n) / math.log10(3)
        return True if tmp - int(tmp)==0 else False
