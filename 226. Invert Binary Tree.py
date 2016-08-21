'''
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.

'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        #先递归到叶子节点然后从叶子往上顺序开始左右交换
        
        '''
        if root == None: return root
        else:
            root.left,root.right = self.invertTree(root.right),self.invertTree(root.left)
            return root
        '''
        
        #从上往下边交换边递归
        if root:
            root.left, root.right = root.right, root.left 
            self.invertTree(root.left)
            self.invertTree(root.right)
        return root
