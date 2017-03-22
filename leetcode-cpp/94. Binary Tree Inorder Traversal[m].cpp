/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

tags:tree,hash table,stack;98m,144m,145h,173m,230m
*/



/****************************
解题思路：
递归版中序遍历
注意递归基if(!root) return;然后按照顺序递归就可以。
**************************/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        inordertra(root,res);
        return res;
        
    }
    
    void inordertra(TreeNode* root, vector<int>& res){
        if (!root) return; //这个不要忘啊，递归基！！！
        inordertra(root->left,res);
        res.push_back(root->val);
        inordertra(root->right,res);
    }
};

/******************************
解题思路：
迭代版本，观察访问路线：线吧root的最左边的节点都入栈，然后从最左边的叶子结点开始出栈并访问val，认为他们是父节点，
父节点访问过是RC，考虑RC子树的最左边的节点都入栈，重复这个过程，直到没有节点可以在压入栈，空栈。

68 / 68 test cases passed.
Status: Accepted
Runtime: 3 ms

3.10%
时间复杂度O(n), 空间复杂度O(n)都入栈
*********************************/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        
        while(1){
            inordertra(root,s); //先把root的左边节点都入栈
            if(s.empty()) return res;
            root = s.top();  //从最左边的叶子节点开始出栈
            s.pop();
            res.push_back(root->val); //遍历val
            root = root->right;//因为栈中保存的都是父节点，中序访问过父节点是RC
            //然后RC树的左右左边的节点都入栈，循环这个过程
        }
        
    }
    
    void inordertra(TreeNode* root, stack<TreeNode*>& s){
        while(root){
            s.push(root);//吧父节点都入栈，知道NULL
            root = root->left;//不管NULL，一直到最左边的叶子，如果为叶子之后的NULL，循环自动断开。
        }
    }
};


/************************
解题思路：
上面的调用函数的改写版，不需要调用函数。吧调用函数的位置用气函数内容换了。
************************/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        
        //考虑出战和入栈两个过程
        while(1){
            if(root){//如果节点存在
                s.push(root);//入栈，原理和上面的方法相同，只是写法不同
                root = root->left; //一直找到最左面的叶子节点
            }
            else if(!s.empty()){//如果找到最左面的叶子结点了，且栈不空
                root = s.top();
                s.pop();
                res.push_back(root->val);//存入父节点的val
                root = root->right;//中序遍历，父节点之后是RC
            }
            else
                return res;//到叶子节点了，且栈空了，证明没有父节点要访问了，结束
        }
    }
};
