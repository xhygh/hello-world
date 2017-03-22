/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

tags: tree,stack; 94m
*/

/*************************
解题思路：
递归版本，面试的时候不要用，人家也不让用，但是写来自己看的。

67 / 67 test cases passed.
Status: Accepted
Runtime: 3 ms
3.14%
时间复杂度O(n)有一个根节点就要调用一次。
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        pretraveral(root, res);
        return res;
    }
    
    void pretraveral(TreeNode* root, vector<int>& res){
        //递归基
        if (!root) return;
        res.push_back(root->val);  //先root
        pretraveral(root->left, res);//左孩子
        pretraveral(root->right, res);//右孩子
    }
};

/****************************
解题思路：
迭代版本，背下来！
观察可知，每次都是把"root"节点的最左边的节点先依次访问，然后从最下面的开始，访问每个节点的右孩子，
而右孩子中又先访问其左孩子。

鉴于先后顺序，使用栈，从root开始，将节点的RC入栈，然后随时把节点的RC入栈，如果LC==NULL那么就可以出栈一个元素，
又RC==null时，又可以出栈一个元素，如此遍历整个树。

67 / 67 test cases passed.
Status: Accepted
Runtime: 3 ms
3.14%
时间复杂度O(n)，空间复杂度O(最大右孩子数？)
要将root看成一个树的子树，如此还调用函数!!!
***********************************/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        
        while(1){
            storeRC(root, res, st); //遍历左边的节点，右边的节点入栈
            if(st.empty()) return res;
            root = st.top();//返回栈顶元素RC
            st.pop();//删除栈顶元素，无返回值
        }
    
    }
    //考虑root节点，入栈其右孩子
    void storeRC(TreeNode* root, vector<int>& res, stack<TreeNode*>& st){
        while(root){
            res.push_back(root->val);//根节点val遍历
            if (root->right) st.push(root->right); //如果有右孩子就入栈
            root = root->left;
        }
    }
};
/**************************
解题思路：
尾递归改迭代法，用栈保存递归的顺序,这个迭代版本比较简单，好理解
67 / 67 test cases passed.
Status: Accepted
Runtime: 3 ms
3.14%
时间复杂度O(n)，空间复杂度O(n)
****************************/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        TreeNode* tmp;
        st.push(root);
        while(!st.empty()){
            tmp = st.top(); // 栈顶元素出栈
            st.pop();
            
            res.push_back(tmp->val); //root的val保存
            
            if (tmp->right) st.push(tmp->right);
            if (tmp->left) st.push(tmp->left);
        }
        return res;
    }
    
};
