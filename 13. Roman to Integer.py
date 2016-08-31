"""
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
"""

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        res = dict[s[-1]]
        pre = res
        for ch in s[::-1][1:]:
            res = res + dict[ch] if dict[ch]>= pre else res - dict[ch]
            '''
            if dict[ch] >= pre:
                res += dict[ch]
            else:
                res -= dict[ch]
            '''
            pre = dict[ch]
        return res
