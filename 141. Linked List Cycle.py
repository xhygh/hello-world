"""
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        #approach1
        #记录已阅的node,每次移动判断是否已阅,in方法
        #Time Limit Exceeded 
        """
        tmp=[]
        while head is not None:
            if head in tmp:
                return True
            tmp.append(head)
            head = head.next
        return False
            
        """
        
        #approach2
        #转化为追击问题-小学生的天下
        
        #if head is None or head.next is None:
        #    return False
        
        p1 = p2 = head
        while p2  and p2.next:
            p1, p2 = p1.next, p2.next.next
            if p1 == p2:
                return True
        return False
        
