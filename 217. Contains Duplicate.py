'''
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct

'''

'''
set保证元素唯一，如果没有重复的元素则set之后长度不变，否则不同，len(set(nums))<=len(nums)
'''
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums=sorted(nums)
        set_nums=sorted(list(set(nums)))
        if nums==set_nums:
            return False
        return True
