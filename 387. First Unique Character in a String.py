'''
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
'''
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt=sorted(dict(collections.Counter(s)).items(),key=lambda i:i[1])
        min=len(s)
        for k in cnt:
            min = s.find(k[0]) if s.find(k[0])<min and k[1]==1 else min
        if min<len(s):
            return min
        else:
            return -1
