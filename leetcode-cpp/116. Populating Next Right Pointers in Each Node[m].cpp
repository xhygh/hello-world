/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree 
(ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
    
tags:tree,depth-first search;117m,119m
*/
 
/***************
solution:
给出一颗二叉树，有left，right，next3个指针。令next指向next right node，初始时，所有next=NULL;
只能用常数的额外空间;假设所有的叶子在同一层，每个parent都有left和right；

连个而外指针，一个经由最左边的node，遍历各层，一个在个层内便利，连接该层的孩子。
14 / 14 test cases passed.
Status: Accepted
Runtime: 22 ms
32.71%
O(n),O(1)
*****************/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    TreeLinkNode* head = NULL;//指向父节点层首节点
    TreeLinkNode* curr = NULL;//指向父节点层便利
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        head = root;
        while(head->left){//当下一层还有元素
            curr = head;//处理当前层,当前层是刚刚链接的层
            while(curr){//如果当前节点存在，进行链接
                curr->left->next = curr->right;//链接当前节点的左右孩子
                if(curr->next) curr->right->next = curr->next->left;
                curr = curr->next;//处理下一个元素
            }
            head = head->left;//下一层
        }
    }
};
