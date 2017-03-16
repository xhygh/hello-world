/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

tags:array;289m
*/

/********************
解题思路1：
使用2个set记录出现0的行和列，然后逐个设为0
时间复杂度O(mn),空间复杂度O(m+n)

157 / 157 test cases passed.
Status: Accepted
Runtime: 66 ms
********************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m,1);
        vector<bool> col(n,1);
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j)
            if(matrix[i][j]==0){
                row[i]=0;
                col[j]=0;
            }
        }
        for(int i=0;i<m;i++)
            if(row[i]==0)
                for(int j=0;j<n;j++)
                    matrix[i][j]=0;
        for(int j=0;j<n;++j)
            if(col[j]==0)
                for(int i=0;i<m;++i)
                    matrix[i][j]=0;
            
    }
};



/******************
解题思路2：
使用其中一行和其中一列作为标志行、列，
在标志行中的每个元素作为该列是否有0，如果有，该元素设为0。
同理标志列中的每个元素作为该行是否有0，如果有，该元素设为0.
最后遍历标志行列，元素为0所在的列行设为0
时间复杂度O(mn),空间复杂度O(1)
注意：统计的时候，要跳过[0][0]位置，
因为这个位置为0，可能不是代表第一行和第一列同时为0，例如[[1,1,1],[0,1,2]]
如果[0][0]被污染了，那结果可能就变成全是0了，但实际只有第一列和第二行为0。
所以0行0列的情况用2个bool变量标志。
157 / 157 test cases passed.
Status: Accepted
Runtime: 53 ms
85.20%
*******************/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0=1;
        bool col0 = 1;
        // 判断0列是否含0
        for(int i = 0;i<m;i++)
            if(matrix[i][0]==0){
                col0 = 0;break;
            }
        //判断0行是否有0
        for(int j = 0;j<n;j++)
            if(matrix[0][j]==0){
                row0 = 0;break;
            }
        //判断其他行列是否有0
        for(int i = 1;i<m;++i)
            for(int j = 1;j<n;++j)
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0; //标志行列
        //其他行列根据0行0列的标志置0
        for(int i=1;i<m;i++)
            if(matrix[i][0]==0)
                for(int j=1;j<n;j++) matrix[i][j]=0;
        for(int j=1;j<n;++j)
            if(matrix[0][j]==0)
                for(int i=1;i<m;++i) matrix[i][j]=0;
        //处理0行0列是否置0
        if(row0==0) //0行有0
            for(int j=0;j<n;++j) matrix[0][j]=0;
        if(col0==0)
            for(int i=0;i<m;++i) matrix[i][0]=0;
    }
};

