"""
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w 
as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2,
since a node can be a descendant of itself according to the LCA definition.
"""
'''
思路：
与本题类似的题是把BST换成普通的二叉树，方法为divide & conquer
对于本题，初始如果root为空，则直接返回None
如果有其中一个node跟root相等，则返回root
以上两两种情况都不满足，考虑到是一棵平衡二叉树，所以有以下三种情况
如果两个node中的较小值都大于root.val，则答案一定在右子树
如果两个node中的较大值都小于root.val，则答案一定在左子树
或者root.val的值介于两个node的值中间，则返回root

文／Jason_Yuan（简书作者）
原文链接：http://www.jianshu.com/p/3b6e9bf1f2f7
著作权归作者所有，转载请联系作者获得授权，并标注“简书作者”。
'''
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root == None: return root
        elif root.val==p.val or root.val==q.val: return root
        elif min(p.val,q.val) > root.val: return self.lowestCommonAncestor(root.right,p,q)
        elif max(p.val,q.val) < root.val: return self.lowestCommonAncestor(root.left,p,q)
        elif min(p.val,q.val) <root.val and max(p.val,q.val) > root.val:return root
            
