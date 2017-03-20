/*

Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. 
t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original 
string by deleting some (can be none) of the characters without disturbing the 
relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, 
and you want to check one by one to see if T has its subsequence. 
In this scenario, how would you change your code?

tags:binary search, DP, greedy;
*/

/********************
解题思路：
连个指针，一个ss = s.begin(),一个tt=t.begin().

遍历string t，在tt<t.end()时，如果*ss==*tt，则++s,并判断是否ss>=s.end()是则return true，每次循环中++tt；

跳出循环后，表示遍历t之后都没有找到s，return false。
【注意边界情况】：
""也算作包括""在内的字符串的有序子集！！！！！！！！！！！！！！！！
14 / 14 test cases passed.
Status: Accepted
Runtime: 72 ms
82.10%

时间复杂度O(s)~O(t)，空间复杂度O(1)
**********************/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true; //【空字符串也算作所有字符串的子集】
        else if(t.empty() ||s.size()>t.size()) return false;
        
        string::iterator ss=s.begin(),tt = t.begin();
        
        while(tt<t.end()){
            
            if(*ss == *tt){
                ++ss;
                if(ss>=s.end()) return true;
            }
            ++tt;
        }
        return false;
    }
};


/*********************DP,GREEDY方法待补充***********************/

