"""
Given an integer, write a function to determine if it is a power of two.
"""

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        '''
        #method1
        #8=1000,7=0111,8&7=0
        if n<=0 or n & (n-1) :
            return False
        return True
        '''
        #method2
        if not n or n<0: return False
        
        tmp = math.log10(n)/math.log10(2)
        
        return True if tmp - int(tmp)==0 else False
