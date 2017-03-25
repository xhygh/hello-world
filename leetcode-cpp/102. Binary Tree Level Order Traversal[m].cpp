/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

tags: tree,breadth-first search;103m,107e,111e
*/

/*********************
解题思路：迭代版
两个queue解决，一个存储本次需要遍历的层的node，一个存储本层node的left和right，
循环直到queue为空。
「注意」用前声明，node存在才能访问left和right
**********************/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> qtmp;
            vector<int> valtmp;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
            
                if (node){//node存在时访问并入队其存在的left和right
                    valtmp.push_back(node->val);
                    if (node->left) qtmp.push(node->left);
                    if (node->right) qtmp.push(node->right);
                }
            }
            q = qtmp;
            res.push_back(valtmp);
        }
        return res;
    }
};
