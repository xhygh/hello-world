"""
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each 
of them is that adjacent houses have security system connected and it will automatically
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
"""
# solution: 
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        '''
        ln = len(nums)
        if not ln:return 0
        elif ln==1: return nums[0]
        #elif ln==2: return max(nums)
        else:
            opt = []
            opt.append(nums[0])
            opt.append(max(nums))
            for i in range(2,ln):
                opt.append(max(opt[i-2]+nums[i],opt[i-1]))
            return opt[-1]
        '''    
        # method2
        if not len(nums): return 0
        
        else:
            lastlast = last = 0
            #for now
            for i in nums:
                lastlast, last = last, max(lastlast + i, last)
            return last
