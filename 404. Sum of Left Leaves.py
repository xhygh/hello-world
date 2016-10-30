"""
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Subscribe to see which companies asked this question
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # root左叶子的值+root右子树的左叶子的值（如果有）
        if not root: return 0
        elif not root.left and not root.right: return 0
        else:
            tmp1 = root.left.val if (root.left and not root.left.left and not root.left.right) else self.sumOfLeftLeaves(root.left)
            tmp2 = self.sumOfLeftLeaves(root.right) if ( root.right and (root.right.left or root.right.right)) else 0
            return tmp1 + tmp2
                    
