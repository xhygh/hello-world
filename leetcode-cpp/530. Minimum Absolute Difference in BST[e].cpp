/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

tags: binary search tree;532e
*/
/*******************************
solution:
一个二叉搜索树，节点值大于等于0，找到差值绝对值最小的二个节点。
根据BST的定义，最小绝对差值应该存在于大小相邻的两个节点之间，因为中序遍历得出有序节点，
所以按照中序便利树，计算节点间的差值即可。
中序遍历时，先遍历较小的，再遍历较大的，所以差值即root->val - last;
因为是遍历，所以每次只要计算当前root值和上一个遍历的节点的val的差值即可，这样肯定时用比上一个val大的数里最小的相减。
186 / 186 test cases passed.
Status: Accepted
Runtime: 19 ms
42.85%
时间复杂度O(n),空间复杂度O(1)
******************************/

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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, last = -1;
        inTravel(root, res, last);
        return res;
    }
    
    void inTravel(TreeNode* root,int& res, int& last){
        if (!root) return;//如果节点不存在直接不考虑
        if(root->left) inTravel(root->left,res,last);//遍历左子树
        if(last>=0) res = min(res, root->val-last);//当前值和上一个节点的值做差，root->val肯定比上一个val大
        last = root->val;//更新val
        if(root->right) inTravel(root->right, res, last);//遍历右子树

    }
};


/*********************上面答案的缩减版，然而时间并未减小***************************/

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
    int res=INT_MAX, last=-1;
public:
    int getMinimumDifference(TreeNode* root) {
        //不能检查root，否则return无int值报错
        //尝试加if(root) 发现!root没有返回也没报错，测试样例中没有root=null的情况
        //if (!root) return;//如果节点不存在直接不考虑
        if(root->left) getMinimumDifference(root->left);//遍历左子树
        if(last>=0) res = min(res, root->val-last);//当前值和上一个节点的值做差，root->val肯定比上一个val大
        last = root->val;//更新val
        if(root->right) getMinimumDifference(root->right);//遍历右子树

        return res;
    }
};
