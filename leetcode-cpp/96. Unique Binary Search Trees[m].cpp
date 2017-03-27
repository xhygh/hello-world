/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
  tags: tree, DP;95m
*/

/*********************
解题思路：
递归法，关于tree的问题很多都是用递归，因为树的局部结构十分相像，天生符合递推关系式。

本题不需要建造树，只要把数量输对即可。
有1....n 这N个数字，选中其中的i作为root，根据BST性质可知，i前面的元素在i的左子树上，i后面的元素在i的右子树上。
设G(n)表示n个数字时BST个数，F(i,n)表示n个数字中，i为root时BST个数。

i为root时，1~i-1为左子树其BST个数为G(i-1)，右子树i+1~n中BST个数为G(n-i),所以F(i,n)=G(i-1)*G(n-i)
而G(n) = F(1, n) + F(2, n) + ... + F(n, n) =  G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0) 
其中G(0)=1,G(1)=1
---------------------------------、


19 / 19 test cases passed.
Status: Accepted
Runtime: 0 ms
40.20%
时间复杂度O(n^2)，空间复杂度O(n)
*********************/
class Solution {
public:
    int numTrees(int n) {
        int G[n+1];
        G[0]=G[1]=1;
        
        for(int i=2;i<n+1;++i){//i表示只有i个元素
            G[i]=0;//没这句19会报错，求教
            for(int j=1;j<=i;++j){//j表示左子树元素个数
                G[i] += G[j-1] * G[i-j];
            }
        }
        return G[n];
    }
};
