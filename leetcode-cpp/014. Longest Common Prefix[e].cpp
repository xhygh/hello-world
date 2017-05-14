/*
Write a function to find the longest common prefix string amongst an array of strings.

tags:string
*/

/*
solution：
找出一系列string的最长公共前缀。

117 / 117 test cases passed.
Status: Accepted
Runtime: 9 ms
10.09%
O(n)~O(nm),O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        for(int j=0;strs.size()>0;++j){
            
            for(int i=0;i<strs.size();++i){
                if(j>=strs[i].size()||(i>0 && strs[i][j]!=strs[i-1][j]))
                    return prefix;
            }
            prefix += strs[0][j]; //更新前缀
        }
        return prefix;
    }
};
