/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

tags:tree,deoth-first search;113m,124h,129m,437e
*/


/*******************************************
解题思路：

深度遍历树。情况如下：
1.root存在问题；
2.到达叶子时，一种是叶子val==剩余sum，返回true；一种是叶子val！=剩余sum，返回false


114 / 114 test cases passed.
Status: Accepted
Runtime: 6 ms
93.35%
时间复杂度O(n),空间复杂度O(1)
**********************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
       if(!root) return false; // 检查是否存在此根
       if(!root->left && !root->right) //如果是叶子结点
           return root->val==sum;//不等于，不是一条path sum；等于则是。
       return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);//否则继续向下遍历考察，存在一条即可
        //不需要考虑左子树和右子树存在否，因为用的是或，如果存在就是有true，最后返回的就是true
       //return (root->left != NULL)&&hasPathSum(root->left, sum-root->val) || (root->right != NULL)&&hasPathSum(root->right, sum-root->val);

    }
};
