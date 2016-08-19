"""
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?
You may find this Wikipedia article useful.


"""

class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        '''方法1
        while(num//10):
            
            temp = [int(i) for i in list(str(num))]
            num = 0
            for i in temp:
                num+=i
        
        return num
        '''
        '''方法2
        while(num//10):
            num = num//10 + num%10
            
        return num
        '''
        """方法3
        
         'd(n)=  1 + （（n-1）%9）'
        
        """
        if num:
            return 1+(num-1)%9
        return 0
