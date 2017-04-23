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
*******************/

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> mps;
		int m = triangle.size();
		mps.push_back(triangle[triangle.size() - 1]); //记录每个元素到bottom的mps

		for (int i = triangle.size() - 2; i >= 0; --i){
			cout << i << endl;
			vector<int> elemps;
			int j = 0;
			for (; j<triangle[i].size(); ++j){
				cout << j << endl;
				cout << triangle[i][j] << endl;
				cout << mps[m - i - 1][j] << endl;
				cout << mps[m - i - 1][j + 1] << endl;
				elemps.push_back(triangle[i][j] + min(mps[m - i - 1][j], mps[m - i - 1][j + 1]));
			}
			mps.push_back(elemps);
		}
		return mps.back()[0];
	}
};
