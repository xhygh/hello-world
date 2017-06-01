/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

tags:array,DP;
*/

/*************
机器人在左上角，标着start，机器人在任何一点仅仅可以通过下移或者右移。
机器人需要到达右下角标着finish的地方，有多少种可能的不同路径。
网格大侠m*n
solution:
深搜思想：return 往下走当解法+往右走当解法（注意边界处理）递归即可。
*************/

/*************深搜超时*************/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1||n<1) return 0;//终止条件
        if(m==1&&n==1) return 1;//收敛条件
        
        return uniquePaths(m-1,n)+uniquePaths(m,n-1);//两个移动方式当解法相加
    }
};

/****************深搜备忘录
61 / 61 test cases passed.
	Status: Accepted
Runtime: 3 ms
2.72%
O(mn),O(mn)

*****************/

class Solution {
public:
    int uniquePaths(int m, int n) {
        f=vector<vector<int>>(m,vector<int>(n,0));
        f[0][0]=1;
        return dfs(m-1,n-1);

    }
    
private:
    vector<vector<int>> f;//备忘录
    
    int dfs(int m,int n){
        if(m<0||n<0) return 0;//终止条件
        if(m==0&&n==0) return f[0][0];//收敛条件
        return f[m][n]>0?f[m][n]:f[m][n]=(dfs(m-1,n)+dfs(m,n-1));//走到过，直接返回;没有走到这里过，算上两种方式到达当解法
    }
};


/**********************
DP方法
**********************/
