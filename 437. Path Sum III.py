"""
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
tags:tree
https://leetcode.com/tag/tree/
====================================================================================
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        # 在root为根的树下找sum的path,找到则res++
        def dfs(root, sum):
            if not root: return 0
            res = (sum==root.val)  # 首先判断root.val是否合格
            res += dfs(root.left, sum-root.val)  # 再判断左子树是否有满足条件的子path，并减去root.val
            res += dfs(root.right, sum-root.val)  # 再判断右子树是否有满足条件的子path，并减去root.val
            return res  #返回以root为根的path数量
        if not root: return 0
        ans = dfs(root,sum)  # 先找以root为根的path
        ans += self.pathSum(root.left, sum)  # 再找以left为根的path
        ans += self.pathSum(root.right, sum)  # 再找以right为根的path
        return ans 
