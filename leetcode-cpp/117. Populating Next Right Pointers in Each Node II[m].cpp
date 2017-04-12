/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
    
tags:tree,depth-first search;116M
*/

/********************
solution:迭代版本
使用额外常数空间，对于任意二叉树进行link。
对116m进行改造，由于不是每个node都是有2个孩子，所以要判断head指向没一层第一个有孩子的，有孩子的还要分是那个孩子。
prev保存下一层被链接的last node。
61 / 61 test cases passed.
Status: Accepted
Runtime: 26 ms
54.58%
O(n),O(1)
**********************/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* head=root;//当前层第一个有孩子的节点
        while(head!=NULL && (head->left||head->right)){//当还有下一层
            TreeLinkNode* curr = head;//从当前层第一个有孩子的节点开始
            head = curr->left?curr->left:curr->right;//head指到下一层
            while(curr){//当前层还有节点
                TreeLinkNode* prev;
                if(curr->left){

                    if(curr->right){
                        curr->left->next = curr->right;//左右孩子都有，链接
                        prev = curr->right;
                    }
                    else//只有左孩子
                        prev = curr->left;
                }
                else//如果只有right
                    prev = curr->right;
                TreeLinkNode* next = haveChild(curr->next);
                if(!next)
                    break;//没有后续的node本层结束
                prev->next = next->left?next->left:next->right;
                curr = next;//中间没孩子的跳过
            }
            head = haveChild(head);//head指向下一层第一个有孩子的节点
           
        }
    }
    
    TreeLinkNode* haveChild(TreeLinkNode* root){
        while(root){
            if (root->left||root->right)
                return root;//返回从root开始，本层有孩子的node
            root = root->next;
        }
        return NULL;
    }
};
