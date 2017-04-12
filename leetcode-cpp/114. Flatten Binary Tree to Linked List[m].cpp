/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

tags:tree,depth-first search
*/

/****************
solution:
把原先的树整理成一个只有右孩子的树。
递归，记录当前节点左子树和右子树当末端，如果有左子树和右子树，那么左子树变右子树，右子树link到leftend，return rightend;
如果只有左子树，左变右，return leftend;
如果只有右子树，return rightend;
如果是叶子，return 当前节点。
225 / 225 test cases passed.
Status: Accepted
Runtime: 6 ms
28.02%
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
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        link(root);
    }
    
    TreeNode* link(TreeNode* root){
        if(!root) return NULL;
        TreeNode* leftend = link(root->left);//左子树末端
        TreeNode* rightend = link(root->right);//右子树末端
        if(root->left){//如果存在左子树
            if(root->right){//如果同时存在右子树
                TreeNode* tmp = root->right;//保存右子树
                root->right = root->left;
                root->left=NULL;
                leftend->right = tmp;
                return rightend;//返回右子树末端
            }
            else{//如果只有左子树
                root->right = root->left;
                root->left=NULL;
                return leftend;
            }
        }
        else if(root->right)//如果只有右子树
            return rightend;
        return root;//如果是叶子节点，末端就是叶子
    }    
};


/**************
solution:
递归版本，右子树link到左子树最右边当叶子节点，左子树变右子树，遍历所有节点。
从最简单的3个节点考虑，
如果root==NULL，return;
右子树link到左子树最右边当叶子处。

225 / 225 test cases passed.
Status: Accepted
Runtime: 6 ms
28.02%
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
    TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
        /**
         *当到达叶子节点的时候，由于先flatten(right)，所以prev=右叶子，然后flatten(left)，prev=左叶子，
         * 回到root的时候，左叶子link到右孩子，而原本的右孩子已经作为左孩子的右孩子了。
        */
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }  
};


/**************
solution:
同上考虑，非递归版本。
从上至下，右孩子link到左孩子最右的叶子，在左孩子变右孩子

225 / 225 test cases passed.
Status: Accepted
Runtime: 6 ms
*************/

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
    TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left && root->right){
                TreeNode* tmp = root->left;
                while(tmp->right)
                    tmp = tmp->right;//一直找到左孩子最右边的叶子
                tmp->right = root->right;//当前节点的右孩子link到其左孩子最右边的叶子上
            }
            if(root->left)
                root->right = root->left; // 左孩子放在右边
            root->left = NULL;//左孩子清空
            root = root->right;//处理下一个节点
        }
    }
};
