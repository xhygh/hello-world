"""
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

Tags:Math
https://leetcode.com/tag/math/
"""
# ======================================================
# 每位可以转化成int加和，记录进位和余下的
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        i1 = len(num1)
        i2 = len(num2)
        carry = 0 # 进位
        res = ''
        while i1 or i2 or carry:
            digit = carry
            if i1:
                i1 -=1
                digit += int(num1[i1])
            if i2:
                i2-= 1
                digit += int(num2[i2])
            carry = digit >9
            res = str(digit%10) + res
        return res
