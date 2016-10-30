"""
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
"""


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = collections.Counter(s)
        #c = sorted(cnt.items(), lambda x,y:cmp(x[1],y[1]), reverse=True)
        L = 0
        cnt2 = 0
        cnt3 = 0
        for i in cnt:
            """
            if i[1]%2==0:
                L += i[1]
            else:
                cnt2 += 1
                if i[1]>1:
                    cnt3 += 1
                    L += i[1]-1
            """
            if cnt[i]%2==0:
                L += cnt[i]
            else:
                cnt2 += 1
                if cnt[i]>1:
                    cnt3 += 1
                    L += cnt[i]-1
        if cnt2>=cnt3 and cnt2!=0: #如果有奇数,最大奇数个字母放中间
            L += 1
        return L 
        
        # approach2 简化1
                cnt = collections.Counter(s)
        L = 0
        cnt2 = 0
        for i in cnt:
            if cnt[i]%2==0:
                L += cnt[i]
            else:
                cnt2 += 1
                L += cnt[i]-1
        if cnt2>0: #如果有奇数,则+1
            L += 1
        return L 
