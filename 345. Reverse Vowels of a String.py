"""
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
"""
'''
Yesterday, some strange things have happened, s=list (s), return ''.join (s) but it was still a list, OJ and local IDE is so. 
You need to change a variable, such as res=list (s). Today it is all good.
'''
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s or len(s) == 1: return s
        start = 0
        end = len(s) - 1
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        s = list(s)
        while True:
            while s[start] not in vowels and start < end:
                start += 1
            while s[end] not in vowels and start < end:
                end -= 1
            if start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1
            else:
                return ''.join(s)
            
