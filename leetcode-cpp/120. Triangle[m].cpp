/**
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

tags:array,DP;
*/

/*******************
solution:
动态规划思想。
想求[i,j]位置到bottom的mps，那么如果知道[i+1,j]或者[i+1,j+1]的mps，取其最小，再加上[i,j]即可。
以OPT(i,j)表示[i,j]位置到bottom的mps，则，递归表达式为：
opt(i,j)=min(opt(i+1,j),opt(i+1,j+1)) + [i,j]
本方法需要保存所有元素到bottom的mps。

43 / 43 test cases passed.
Status: Accepted
Runtime: 6 ms
O(n^2),O(n^2)
*******************/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> mps={triangle[m - 1]};   //记录每个元素到bottom的mps
        for (int i = m - 2; i >= 0; --i){
            vector<int> elemps;
            for (int j = 0; j<m; ++j)
                elemps.push_back(triangle[i][j] + min(mps[m - i - 2][j], mps[m - i - 2][j + 1]));
            mps.push_back(elemps);
        }
        return mps.back()[0];//返回[0,0]元素到bottom的mps
    }
};


/******************
solution:
使用O(n)空间，需要记录每行元素到bottom的mps，而不是每个元素到bottom的.
我们计算[i,j]位置的mps时候，只需要i+1行的数据即可，所以可以“覆盖”。
对于上面的解法，使用“覆盖”trick，由于每一层都比上一层多一个，所以从下至上覆盖是可以的。
仅使用最有一层大小的空间存储每层元素的mps，最后返回第一个元素即可。
对于第k层的mps，递归式为：
opt(i) = min(opt(i),opt(i+1)) + nums[k][i]
O(n^2),O(n)
****************/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> mps=triangle[m - 1];   //记录每层每个元素到bottom的mps，之后上层覆盖下层
        for (int i = m - 2; i >= 0; --i)
            for (int j = 0; j<m; ++j)
                mps[j] = (triangle[i][j] + min(mps[j], mps[j + 1]));
        return mps[0];//返回[0,0]元素到bottom的mps
    }
};
