/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

tags:DP;140h
*/

/*****************
solution:
考虑字符串s，对于长度[0,i]可以分割，那么考虑[0,i+1]是否可以分割。
f[0:s.size()]记录[0,i]是否可以分割，对于长度[0,i+1]，遍历f，看看f[j]，0<=j<i,即s[0:j]是否可以分割，另外[j+1,i+1]是否是dict中的单词，
如果是，那么f[i]=True，返回f[s.size()]的结果
*******************/
