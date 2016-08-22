'''
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

'''



class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        
        p0,length = 0,len(nums)
        for pn in range(length):
             if nums[pn]==0:
                 continue
             else:
                 nums[p0],nums[pn]=nums[pn],nums[p0]
                 p0+=1
        
        '''
        
        p0,pn=0,0
        if pn<len(nums) and p0 <len(nums):
            while nums[p0]!=0:
                p0+=1
                pn+=1
            while nums[pn] ==0 and pn<len(nums):
                pn+=1
            while pn<len(nums) and p0 <len(nums):
                nums[p0],nums[pn]=nums[pn],nums[p0]
                p0+=1
                while pn<len(nums) and nums[pn] == 0 :
                    pn+=1
         '''
