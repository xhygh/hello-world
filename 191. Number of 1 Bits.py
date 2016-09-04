"""
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
"""
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        '''
        if n<0 or 'int' not in str(type(n)):
            return False
        bina = bin(n)[2:]
        cnt = collections.Counter(bina)
        return cnt['1']
        '''
        """
        return bin(n).count('1')
        """
        cnt = 0
        while n:
            cnt += 1
            n &= (n-1)
        return cnt
