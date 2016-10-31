"""
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

Tags:Tree, Breadth-first Search
https://leetcode.com/tag/tree/
https://leetcode.com/tag/breadth-first-search/
"""
# =========================================================

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        # level-order traverse
        if root:
            q = [root]
            res = []
            while  q:
                q_new = []
                res.append([eachnode.val for eachnode in q])
                for eachnode in q:
                    if eachnode.left:
                        q_new.append(eachnode.left)
                    if eachnode.right:
                        q_new.append(eachnode.right)
                q = q_new
            return res
        return []
