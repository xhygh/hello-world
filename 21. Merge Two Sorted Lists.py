"""
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        '''
        head = ListNode(0)
        tmp = head
        while l1 and l2:
            if l1.val<=l2.val:
                tmp.next = l1
                l1 = l1.next
            else:
                tmp.next = l2
                l2 = l2.next
            tmp = tmp.next
        tmp.next = l1 if l2==None else l2
        return head.next
        '''        
        #递归
        if l1 is None: return l2
        if l2 is None: return l1
        if (l1.val<=l2.val):
            tmp = l1
            tmp.next = self.mergeTwoLists(l1.next, l2)
            return tmp
        else:
            tmp = l2
            tmp.next = self.mergeTwoLists(l1, l2.next)
            return tmp
        
        
             
