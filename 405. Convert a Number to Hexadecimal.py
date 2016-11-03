"""
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
tags: Bit Manipulation
https://leetcode.com/tag/bit-manipulation/
"""

# 不需要考虑补码怎么求，计算机里面就是二进制补码表示的，只需把数字表示成32位二进制，然后每四位映射成一个16进制数字，最后去掉前导0
class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        res=[]
        for i in range(8):
            res.append('0123456789abcdef'[num&15])
            num >>= 4
            if num==0: break  # 多余的0就不要了，只有0才能以0开始
        return ''.join(res[::-1])
