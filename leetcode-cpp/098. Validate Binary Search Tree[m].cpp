/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

tags:tree,depth-first search;94m,501e
*/


/*************
solution:
BST树，中序便利得到严格升序的数列。从这点下手，遍历每个节点，和前一个节点的数值比较，如果大于则true;
具体：设置一个全局变量prev，记录前一个node的val，不可以用INT_MIN初始化，以为不是比大小，而且如果root->val==INT_MIN就会判断失误;
获得左子树的比较结果，叶子节点的左子树return true即可;
获取当前节点val与prev对比，得到当前节点顺序判断结果;
获取右子树判断结果;
return left && curr && right即可。

74 / 74 test cases passed.
Status: Accepted
Runtime: 9 ms
57.17%
O(n),O(1)
**************/
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
    int *prev = NULL;//不可用INT_MIN初始化，如果root->val==INT_MIN会出现判断错误
public:
    bool isValidBST(TreeNode* root) {
        //中序遍历，后一个比前一个大
        if(!root) return true;
        bool left = isValidBST(root->left);
        bool curr;
        if(!prev){// 如果这是第一个数据
            prev = &(root->val);//初始化prev
            curr = true;//因为是第一个数据，无论放谁都是对的
        }
        else{//如果不是第一个数据，就要和前一个数据保持严格升序关系，不可等于
            curr = (root->val > *prev);//不可以等于，左小，右大
            prev = &(root->val);
        }
        bool right = isValidBST(root->right);//检查右子树
        return left && curr && right;//大家都有序才是真的有序
    }
};


/*************
上面的修改版，变慢了
74 / 74 test cases passed.
Status: Accepted
Runtime: 16 ms
9.48%
***************/
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
    int *prev = NULL;//不可用INT_MIN初始化，如果root->val==INT_MIN会出现判断错误
public:
    bool isValidBST(TreeNode* root) {
        //中序遍历，后一个比前一个大
        if(!root) return true;
        if(!isValidBST(root->left))
            return false;//如果左子树不是
        bool curr;
        if(prev!=NULL && *prev>=root->val)
            return false;//如果当前节点顺序不对
        prev = &(root->val);
        //到这里证明前面都是true
        return isValidBST(root->right);//直接返回右子树结果即可
    }
};
