/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

tags:tree,array,depth-first search;106m
*/


/*************************
解题思路：
题目是给出一个树的先序和中序遍历，构造这棵树。
递归法构造树。
假设我们输入的是一个根节点的左子树或者右子树，我们继续下分，将每个节点视为一个子树的root即可。
所以有可能两个输入是空，如果是空，代表他们的father是叶子node。
*************************/


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recBuildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    
    TreeNode* recBuildTree(vector<int>::iterator pre_first,vector<int>::iterator pre_last, vector<int>::iterator in_first, vector<int>::iterator in_last){
        if(pre_first == pre_last) return NULL;
        if(in_first == in_last) return NULL;
        
        TreeNode* root = new TreeNode(*pre_first);//先序的第一个为根节点
        
        //划分左右子树
        vector<int>::iterator inRootPos = find(in_first, in_last, *pre_first);//在中序中找到根，前面的是左子树的，后边的是右子树的
        int leftSize = distance(in_first, inRootPos);//获取左子树规模[in_first, inRootPos)间元素个数
        root->left = recBuildTree(pre_first+1,pre_first+leftSize+1,in_first,in_first+leftSize);
        root->right = recBuildTree(pre_first+leftSize+1,pre_last,in_first+leftSize+1,in_last);
        return root;
        
    }
};
