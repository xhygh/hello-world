/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

*/

/******************
前序遍历中，第一个元素是root，但是中序遍历的root在中间，前边的是left，后边的是right。
所以，通过前序遍历确定root，然后遍历中序结果找到root，根据中序中的left和right确定前序结果中的left和right，
然后同样确定下一个root（就是left的root），在中序中（left）中在找新root，循环迭代。

本答案用序号index，也可以用迭代器和长度
******************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		/*
        *中序遍历，中间的是树根，左边是left，右边是right
        *前序遍历，第一个是root，然后是left，然后是right
        *分解，递归解决即可
        */
        if(pre.size()<=0||pre.size()!=vin.size()) return nullptr;
        int n = pre.size();
        
        return constructTree(pre,0,n-1,vin,0,n-1);//return root
        
    }
    TreeNode* constructTree(vector<int>& pre,int pre_s, int pre_e,vector<int>& vin,int vin_s,int vin_e){

        TreeNode* root = new TreeNode(pre[pre_s]); //先序遍历的第一个节点是root
        if(pre_s==pre_e){
            if(vin_s==vin_e && pre[pre_s]==vin[vin_s])
            	return root;
            else
                throw "Invalid input.";
        }
        int root_idx = -1;
        for(int i=vin_s;i<=vin_e;++i){
            if(vin[i]==root->val){
                root_idx = i;
                break;
            }
        }
        if(root_idx==vin_e && vin[root_idx]!=vin[vin_e])
            throw "Invalid input.";
        if(root_idx-1>=0&&pre_s+1<=pre_s+root_idx-vin_s&&vin_s<=root_idx-1)//没有做子树
        	root->left = constructTree(pre,pre_s+1,pre_s+root_idx-vin_s,vin,vin_s,root_idx-1);
        if(root_idx+1<pre.size() && pre_s+root_idx-vin_s+1<=pre_e&&root_idx+1<=vin_e)//没有右子树
        	root->right = constructTree(pre,pre_s+root_idx-vin_s+1,pre_e,vin,root_idx+1,vin_e);
        return root;    
    }
    
};
