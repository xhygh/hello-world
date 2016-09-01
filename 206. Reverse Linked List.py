"""
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #iteratively
        '''
        if head == None or head.next == None:
            return head
        tmp = head
        head = head.next
        tmp.next = None
        while head != None:
            head.next, tmp, head= tmp, head, head.next
        return tmp
        '''
        
        new_head = None
        while head:
            tmp = head
            head = head.next
            tmp.next = new_head
            new_head = tmp
        return new_head
    
        
        #recursively
