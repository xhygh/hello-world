"""
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

"""

class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        #method1
        '''
        res=[]
        if len(nums1) > len(nums2):
            nums1,nums2 = nums2,nums1
        for elem in nums1:
            if elem in nums2:
                res.append(elem)
                nums2.remove(elem)
        return res
        '''
        #method2 for memory limited
        res=[]
        if len(nums1) > len(nums2):
            nums1,nums2 = nums2,nums1
        cnt = collections.Counter(nums1)
        for elem in nums2:
            if cnt[elem] > 0:
                res.append(elem)
                cnt[elem] -= 1
        return res
