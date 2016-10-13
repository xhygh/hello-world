"""
Question:
Given a string, we can "shift" each of its letter to its successive letter, 
for example:"abc" -> "bcd". We can keep "shifting" which forms the sequence:"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given:["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Return:
[

  ["abc","bcd","xyz"],

  ["az","ba"],

  ["acef"],

  ["a","z"]

]
"""


# 参考自http://blog.csdn.net/pointbreak1/article/details/48780345
# 太魔性看完忘不了了
class Solution(object):
    def groupStrings(self, strings):
        """
        :type strings: List[str]
        :rtype: List[List[str]]
        """
        tmp = collections.defaultdict(list)
        for s in strings:
            shift = tuple([(ord(char) - ord(s[0])) % 26 for char in s])
            print(shift)
            tmp[shift].append(s)
        return map(sorted, tmp.values())
