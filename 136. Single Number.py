"""
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
"""

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        '''
        tmp=collections.Counter(nums)
        for key in tmp:
            if tmp[key]==1:
                return key
        '''        
        # method2
        # 从偶数重复次数的数列中找出唯一个奇数次重复的元素，用全体异或x^y
        # 公式如下：
        #  a ^ a = 0
        #  a ^ b ^ a = b ^ a ^ a = b ^ (a ^ a) = b ^ 0 = b

        return reduce(lambda x, y: x ^ y, nums)
        
        # 从奇数次重复的数列中找出唯一个偶数次重复的元素
        # (原问题是1-1000及N(N属于1-1000)放在含有1001个元素的数组中，最多有一个元素值重复，其它均只出现一次，求N)
        # a^a = 0, a^a^a = a 即元素自我异或偶数次为0,奇数次为自我
        # 所以，偶数次重复的元素可归为2次，奇数次的元素可归为1次，得到等价数列，其中重复元素e
        # T = 等价元素序列排除重复一次的e的异或结果即，a^b...^d^e^...^f...
        # T^e =  等价元素序列所有元素异或，即(a^b...^d^e^...^f...)^e
        # T^T^e = e
        # 连续整数异或速算法可提高效率
