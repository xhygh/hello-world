"""
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
"""

class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        flag = True
        for i in range(1,len(digits)+1):
            digits[-i] = digits[-i]+1 if digits[-i]+1<10 else 0
            if digits[-i]!=0:
                flag = False
                break
        if flag is True:
            digits.insert(0,1)
        return digits
            
