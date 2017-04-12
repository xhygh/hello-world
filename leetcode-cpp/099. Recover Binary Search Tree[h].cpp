/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?

tags:tree,depth-first search;

*/


/*******************
solution:
BST中有来两个元素放错位置了，请将他们调换回来，最好用常数空间，不可以改变树的结构。
12 [7 4]5[6 3] 8 两个错误的元素不挨着
[2 1]3  两个错误的元素挨着
[4 2][3 1]
如上面示例，找到第一个降序的位置和第二个降序的位置。
第一次取较大的元素，第二次取较小的元素，将二者调换
中序便利得到有序数列。

1916 / 1916 test cases passed.
Status: Accepted
Runtime: 29 ms
33.95%
O(n),O(1)
*******************/
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
private:
    TreeNode* first=NULL;//记录第1个错误元素
    TreeNode* second=NULL;//记录另一个错误元素，因为有可能和first挨着，所以顺道记录first下一个，可以之后覆盖
    TreeNode* prev=NULL;//记录前1个元素
public:
    void recoverTree(TreeNode* root) {
        twoError(root);
        int tmp = second->val;
        second->val = first->val;
        first->val = tmp;
    }
    
    void twoError(TreeNode* root){
        if(!root) return;
        twoError(root->left);
        if(prev!=NULL && prev->val > root->val){
            //只有发现降序的时候才进入该循环
            if(!first) 
                first = prev;//第一次降序，记录first
            second = root;//第一个降序时的root或者是第二次降序时的root,较小的那个
        }
        prev = root;
        twoError(root->right);
    }
};
