/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as 
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

tags:tree depth-first search;104e

*/

/****************
solution:

高度平衡就是判断这棵树是否为平衡二叉树，平衡二叉树左右子树高度相差小于等于1,
且对于其中每个节点都如此，所以要用递归，深度遍历每个节点，统计其高度。
从叶子开始返回高度，叶子是0,然后左右子树最高的+1
226 / 226 test cases passed.
Status: Accepted
Runtime: 9 ms
42.38%
O(n),O(1)
****************/

/*****实现1*****/
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
    bool isBalanced(TreeNode* root) {
        return balanceHeight(root)>=0;
    }
    
    int balanceHeight(TreeNode* root){
        if(!root) return 0;
        int left = balanceHeight(root->left);
        int right = balanceHeight(root->right);
        
        if(left==-1 || right ==-1 || abs(left-right)>1) return -1;//有一个子树是-1,它所在的root都return -1
        return max(left,right)+1;
    }
};


/************实现2**********/
class solution {
public:
    int depth (TreeNode *root) {//仅仅计算树当高度
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;
        
        int left=depth(root->left);//得到左子树高度
        int right=depth(root->right);//右子树高度
        
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);//对于root和子树当判断联合
    }
};
