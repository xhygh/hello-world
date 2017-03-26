/*

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

tags:tree,depth-first search,breadth-first search;
*/


/************************
解题思路：
树的左右两颗子树是否镜面对称。
利用之前的sameTree方法即可.

[注意]几种情况：空树，单节点树，左右孩子皆存在树，单孩子树。
***********************/

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
    bool isSymmetric(TreeNode* root) {
        if(!root||(!root->left && !root->right)) return true;  //空树,单节点树都是对称的
        if(root->left && root->right) return symmetricTree(root->left,root->right);//左右孩子都存在
        return false;//单孩子树
    }
    
    bool symmetricTree(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;//节点都不存在，不存在的节点无val,下面报错
        if(!l || !r) return false;//单孩子树
        //双孩子树
        return (l->val == r->val && symmetricTree(l->left,r->right) && symmetricTree(l->right,r->left));
    }
};
