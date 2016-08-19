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
        ""
        我的思路是很规矩的来加，比如：

        385 -> 3+8+5 = 16 -> 1+6 = 7

        而他的思路是：

        385 -> 38+5 = 43 -> 4+3 = 7

        为何这样做是对的呢？

        主要看 38+5 与 3+8+5 的不同，38+5 将 8+5 的进位1累加到高位的3上面， 而 3+8+5将 8+5 的进位保留在13中。

        而实际上两者是没有区别的：

        38 + 5 -> (3+1)+3

        3+8+5 -> 3+(10+3) -> 3+1+3
        ""
        
        
        
        
        
        """方法3
        
         'd(n)=  1 + （（n-1）%9）'
        
        """
        if num:
            return 1+(num-1)%9
        return 0
