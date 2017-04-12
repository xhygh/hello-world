/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the 
shortest path from the root node down to the nearest leaf node.


tags: tree depth-first search breadth-first seatch; 102m,104e
*/


/****************
solution:
深度遍历，返回左右子树中最小的+1;
注意其中一个子树为0,一个不为0当情况，这时会返回0,但是不对，应该返回有数据当那个子树高度。
所以只要判断左子树为0,返回右子树高度+1;右子树为0,返回左子树高度+1,即可
41 / 41 test cases passed.
Status: Accepted
Runtime: 6 ms
83.59%
O(n),O(1)
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left==0) return right+1;
        else if (right==0) return left+1;
        return min(left,right)+1;
    }
};


/***********
同上
**********/

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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return min(minDepth(root->right),minDepth(root->left))+1;
    }
};

/*********
solution:
广度优先搜索
搜索每层，使用queue数据结构，minD记录层数，当该层某个节点时叶子节点当时候，return 当前minD。
41 / 41 test cases passed.
Status: Accepted
Runtime: 12 ms
16.98%
<=O(n)，O(1)
*********/
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
    int minDepth(TreeNode* root) {
        int minD = 0;
        if(!root) return minD;
        queue<TreeNode*> layer;
        layer.push(root);
        ++minD;
        while(!layer.empty()){
            queue<TreeNode*> tmp;
            while(!layer.empty()){
                TreeNode* elem = layer.front();layer.pop();
                if(!elem->left && !elem->right) return minD;
                if(elem->left)
                    tmp.push(elem->left);
                if(elem->right)
                    tmp.push(elem->right);
            }
            ++minD;
            layer = tmp;
        }
    }
};
