/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.


tags:tree,depth-first search;
*/

/***********************

解题思路：
题目要求辨别两个二叉树是否相等。相等的条件是：结构一致 & 对应node->val相等。
第一个条件使得我们需要遍历整棵树发现二者结构是否相同；
第二个条件我们不得不真的遍历每个节点的val进行对比。
综上此题是一个树的遍历问题的衍生问题。

遍历方法有递归，迭代和morris
*************************/


/******************先序递归版本**********************/
54 / 54 test cases passed.
Status: Accepted
Runtime: 0 ms74.14%
时间复杂度O(n),空间复杂度O(1)
/***********************************************/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
     return sameTree(p,q);
    }
    
    bool sameTree(TreeNode* p, TreeNode* q){
        if (!p && !q) return true;
        else if (!p || !q) return false;
        else
            return p->val == q->val && sameTree(p->left,q->left) && sameTree(p->right,q->right);
    }
};

/**********************先序迭代版本***********************/
/********************************************************/

