'''
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
'''





class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        '''#methon1
        n1,n2=list(set(sorted(nums1))),list(set(sorted(nums2)))
        i,j=0,0
        res=[]
        
        
        while i<len(n1) and j<len(n2):
            if n1[i]==n2[j]:
                res.append(n1[i])
                if len(n1)-i > len(n2)-j:
                    i=i+1
                else:
                    j=j+1
            elif n1[i]<n2[j]:
                i+=1
            else:
                j+=1
        return res
        '''  
        '''#methon2
        res=[]
        for i in nums1:
            if i in nums2:
                res.append(i)
        return list(set(res))
        '''
        '''#methon3
      
        return list(set([i for i in nums1 if i in nums2]))
        
        '''
        #methon4
        return list(set(nums1)&set(nums2))  
