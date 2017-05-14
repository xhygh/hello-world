/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

tags:math,string;2m,43m,66e
*/
/*
solution:
给出2位字符串，返回她们的二位和字符串。
依照十进制的方法，修改为二进制即可。
计算当前进位c和a,b对应位的加和，留下个位作为本位的结果，需要进位的部分使用除法保留在c上进行下一次加法。

294 / 294 test cases passed.
Status: Accepted
Runtime: 3 ms
30.37%
O(n+m),O(1)
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string s="";
        
        int c=0,ai=a.size()-1,bi=b.size()-1;
        while(ai>=0||bi>=0||c>=1){
            c += ai>=0?a[ai--]-'0':0;
            c += bi>=0?b[bi--]-'0':0;
            s = char(c%2+'0')+s;
            c = c/2;
        }
        return s;
    }
};
