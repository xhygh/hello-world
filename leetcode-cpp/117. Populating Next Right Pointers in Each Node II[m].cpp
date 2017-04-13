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

/******************
solution:
迭代，层次遍历
在116m上小改。与116m不同之处，本体每行的head不一定是上一层head->left，所以加一个变量记录下一个head的位置。
此外要判断是否有孩子。
#是上面那版的缩减版，速度变慢了，因为没有跳过中间没有孩子的node
******************/
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

        TreeLinkNode *now, *head, *tail;
        now = root;
        head=tail=NULL;
        
        while(now){
            if(now->left){//如果有左孩子
                if(tail){//如果有链接的node
                    tail->next = now->left;//之前的node链接到左孩子
                    tail = tail->next;//更新最后的node
                }
                else{//开始链接
                    head = now->left;
                    tail = head;
                }
            }
            if(now->right){//如果有有孩子
                if(tail){
                    tail->next = now->right;
                    tail = tail->next;
                }
                else{
                    head = now->right;
                    tail = head;
                }
            }
            if(!(now=now->next)){//本层下一个node，如果不存在
                now = head;//更新到下一层的开头
                head = tail = NULL;//清空被链接层的指针，等待使用
            }
        }
    }
};

/*********************
solution:
结合前两个方法改进第一个，得到如下结果
61 / 61 test cases passed.
Status: Accepted
Runtime: 23 ms
93.88%
***********************/
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
            TreeLinkNode* prev=NULL;
            while(curr){//当前层还有节点
                
                if(curr->left){

                    if(prev){
                        prev->next = curr->left;//链接左孩子
                        prev = prev->next;//更新连好的最后节点位置
                    }
                    else//只有左孩子
                        prev = curr->left;//如果是第一个node
                }
                if(curr->right){
                    if(prev){
                            prev->next = curr->right;//链接右孩子
                            prev = prev->next;//更新连好的最后节点位置
                    }
                    else//只有左孩子
                        prev = curr->right;//如果是第一个node
                }
                        
                curr = haveChild(curr->next);//下一个有孩子的
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


/*******************
solution:
额外设置head和tail两个指针，这样可以减少很多判断。
#对于树结构，额外设置指针很多时候可以很快解决问题。#
*******************/
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
        while(root){
            TreeLinkNode* head = new TreeLinkNode(0); // 指向即将被链接的一行的第一个节点的额外节点
            TreeLinkNode* curr = head;//当前链接处理的node
            while(root){//刚刚被链接好的一层中的node
                if(root->left){
                    curr->next = root->left;
                    curr = curr->next;
                }
                if(root->right){
                    curr->next = root->right;
                    curr = curr->next;
                }
                root = root->next;//遍历刚刚链接好的一层
            }
            root = head->next;//更新为最新链接好的一层
        }
    }
};
