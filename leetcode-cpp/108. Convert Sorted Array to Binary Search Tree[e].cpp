/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

tags:tree, depth-first search;109m
*/

/***************
solution:
二分法，因为BST的定义是左边<root<右边。

32 / 32 test cases passed.
Status: Accepted
Runtime: 13 ms
78.86%
o(n),O(1)
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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()); //[start,end)范围
    }
    
    TreeNode* BST(vector<int>& nums,int start,int end){
        if(end-start<=0) return NULL;
        int mid = (end+start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BST(nums,start,mid);
        root->right = BST(nums,mid+1,end);
        
        return root;
    }
};
 

/*****************
solution:
[start,end]范围的二分法
*********************/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()-1); // 范围[start,end]
    }
    
    TreeNode* BST(vector<int>& nums,int start,int end){
        if(end-start<0) return NULL;
        int mid = (end+start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BST(nums,start,mid-1);// 范围[start,mid-1]
        root->right = BST(nums,mid+1,end);
        
        return root;
    }
};
