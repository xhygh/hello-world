/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

tags:DP,backtracking,string;44h
*/

/*
正则表达式匹配，'.'可以匹配任意字符，'*'可以匹配任意个(可以为0)'*'之前的字符
    不考虑'*'的话，题目变成简单的匹配。考虑'*'，可能产生的情况有匹配0、1、2…个字符
    因此可以使用递归或dp或其他方法解决
define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise.
如果s和p的为元素能匹配且p的尾元素不是*:
P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
如果p的尾元素为*全能匹配，
P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
*/
