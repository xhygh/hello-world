/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
tags:tree,stack;94m
*/

/*******************
解题思路：
递归版本，只要按照顺序递归即可.

67 / 67 test cases passed.
Status: Accepted
Runtime: 3 ms
3.31%
时间复杂度O(n)，空间复杂度O(1)
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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTrav(root, res);
        return res;
    }
    
    void postorderTrav(TreeNode* root, vector<int>& res){
        if(!root) return;//递归基
        
        postorderTrav(root->left, res);
        postorderTrav(root->right, res);
        res.push_back(root->val);
        
    }
};


/***************
迭代版
通过观察遍历顺序可知，后续遍历类似先序遍历，只不过先序遍历讲father和lc的遍历融合了，
对于每个节点，每次只需要visit father入站rc，root=root->lc，即可。
然后然后弹出栈顶元素，若栈不空，这个rc进行上一步，一直找道它的罪左边的叶子。

后续遍历与先序遍历不同的地方是，在找最左边的叶子节点的时候并不visit 经过的node，因为之后访问的是rc。
但是如果栈保存rc，没有father指针，我们不能回溯其他的node，所以只能存father node。
-----------------------
综上解题思路如下：
1.找到目前节点cur最左边叶子，沿途节点入站;
2.考察栈顶元素t，如果t->right存在且刚才访问的并不是t->right,cur=t->right,如果right不是叶子节点，重复1，如果是叶子节点则访问;
否则，t->right不存在或者刚才访问的即t->right，证明此时需要进行cur节点的访问，访问cur，更新上一被访问节点标志，将处理完的节点出战，循环2.


67 / 67 test cases passed.
Status: Accepted
Runtime: 3 ms
3.10%
时间复杂度O(n),空间复杂度O(n)
****************/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curr = root;//记录当前处理的节点
        TreeNode* last = NULL;//记录上一个处理的节点，因为father和right可能分不清，如果全入栈
        while(curr||!s.empty()){
            if(curr){// 如果当前节点存在，找到其最左叶子并入栈沿途节点
                s.push(curr);
                curr = curr->left;
            }
            else{//找到最左叶子
                TreeNode* top = s.top();//记录目前的栈顶元素
                
                if(top->right && top->right!=last)  //如果栈顶元素有right且并未处理过，处理其right
                    curr = top->right;
                else{//如果栈顶元素没有right或者其right已经处理过,根据post规则，该处理top了
                    res.push_back(top->val);//访问top
                    last = top;//记录刚刚处理过top
                    s.pop();//处理过的节点出栈
                    //然后继续考察栈顶元素
                }
                
            }
        }
        return res;
    }
};
