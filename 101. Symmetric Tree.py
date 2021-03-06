"""
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

Tags:Tree,Depth-first Search, Breadth-first Search
https://leetcode.com/tag/tree/
https://leetcode.com/tag/depth-first-search/
https://leetcode.com/tag/breadth-first-search/
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # Recursive
    # 搞清楚最小元件的特征，找出其对比方法
    '''
    def isMirror(self, t1, t2):
        if t1 is None and t2 is None:
            return True
        if t1 is None or t2 is None:
            return False
        return (t1.val == t2.val) and self.isMirror(t1.left,t2.right) and self.isMirror(t1.right,t2.left)
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isMirror(root,root)
    '''
    
    # (Iterative + Queue)
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        import Queue
        if root is None: return True
        q = Queue.Queue()
        q.put(root.left)
        q.put(root.right)
        while not q.empty():  # 控制结束
            t1 = q.get()
            t2 = q.get()
            if t1 is None and t2 is None: continue
            if t1 is None or t2 is None: return False
            if t1.val != t2.val: return False
            q.put(t1.left)
            q.put(t2.right)
            q.put(t1.right)
            q.put(t2.left)
        return True

    
    # (Iterative + list)
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None: return True
        q = []
        q.append(root.left)
        q.append(root.right)
        while q:
            t1 = q.pop(0)
            t2 = q.pop(0)
            if t1 is None and t2 is None: continue
            if t1 is None or t2 is None: return False
            if t1.val != t2.val: return False
            q.append(t1.left)
            q.append(t2.right)
            q.append(t1.right)
            q.append(t2.left)
        return True
