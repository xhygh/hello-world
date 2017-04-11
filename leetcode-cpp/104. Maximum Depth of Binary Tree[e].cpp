/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the 
longest path from the root node down to the farthest leaf node.

tags:tree depth-first search;111e,110e
*/



/*********************
solution:

深度遍历到叶子节点，返回叶子之下的0高度，叶子在左右返回当0高度上加1,返回自己的高度。
对于树中当node，返回左右子树中最大当高度+1当值即可。
38 / 38 test cases passed.
Status: Accepted
Runtime: 6 ms
38.64%
O(n),O(1)
********************/

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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;//叶子node之下都是0深度
        int left = maxDepth(root->left);//返回左子树高度
        int right = maxDepth(root->right);//返回右子树高度
        return max(left,right)+1;//返回子树最高的高度并+1作为本树当高度
    }
};
