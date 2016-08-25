'''
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
'''

class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        #26jinzhi
        t=ord('A')-1
        le=len(s)-1
        sum=0
        for letter in s:
            sum+=(ord(letter)-t)*(26**le)
            le-=1
            
        return sum
