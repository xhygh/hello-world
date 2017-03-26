/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
tags:tree,breadth-first search stack;102m
*/

/*********
解题思路：
层次遍历的变形，两个想法，一种还是2个queue，bool变量记录是否翻转；一种是stack先进后出.
这里有个坑：zigzag并不是单单的每次将存储的node反序遍历，反序遍历本层node时，他们的孩子也要从right到left保存！
我就在这里犯错了，虽然反序遍历了保存的nodes，但是他们的孩子还是left到right就不对了！

所以用stack，要用bool区分正序l到r和反序r到l；
用queue需要bool区分是否逆序。


33 / 33 test cases passed.
Status: Accepted
Runtime: 3 ms
39.90%
时间复杂度O(n)，空间复杂度O(n)
********/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        stack<TreeNode*> s;//使用stack只需要交换单个节点的左右孩子顺序
                            //如果用queue就需要逆序
        s.push(root);
        
        bool flag= false; //false表示反序
        while(!s.empty()){
            stack<TreeNode*> stmp;
            vector<int> restmp;
            flag = !flag;
            while(!s.empty()){
                TreeNode* t = s.top();s.pop();
                
                restmp.push_back(t->val);
                if(flag){
                    if(t->left) stmp.push(t->left);
                    if(t->right) stmp.push(t->right);
                }
                else{
                    if(t->right) stmp.push(t->right);
                    if(t->left) stmp.push(t->left);
                }
            }
            s = stmp;
            res.push_back(restmp);
        }
        return res;
    }
};
