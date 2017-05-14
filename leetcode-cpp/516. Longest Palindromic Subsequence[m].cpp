/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

tags: DP;5m

http://www.cnblogs.com/grandyang/p/6493182.html
*/

/*
solutiom:
给出一个字符串s，找出最长回文子序列的长度，假设最长的s为1000.

动态规划方法：
longest[i][j]表示【i，j】将字符串的最大回文子串长度，状态转移方程：
longest[i][j] = longest[i+1][j-1]+2，s[i]==s[j]
longest[i][j] = max(longest[i+1][j],longest[i][j-1])，s[i]!=s[j]
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));  // n*n矩阵
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
