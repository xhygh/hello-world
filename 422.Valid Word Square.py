"""
Given a sequence of words, check whether it forms a valid word square.
A sequence of words forms a valid word square if the kth row and column read the exact same string,
where 0 ≤ k < max(numRows, numColumns).

Note:
The number of words given is at least 1 and does not exceed 500.
Word length will be at least 1 and does not exceed 500.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
[
  "abcd",
  "bnrt",
  "crmy",
  "dtye"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crmy".
The fourth row and fourth column both read "dtye".

Therefore, it is a valid word square.
Example 2:

Input:
[
  "abcd",
  "bnrt",
  "crm",
  "dt"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crm".
The fourth row and fourth column both read "dt".

Therefore, it is a valid word square.
Example 3:

Input:
[
  "ball",
  "area",
  "read",
  "lady"
]

Output:
false

Explanation:
The third row reads "read" while the third column reads "lead".

Therefore, it is NOT a valid word square.
"""

def validWordSquare(words):
    """
    :type words: List[str]
    :rtype: bool
    """
    # m:rows,n:cols
    # approach 1
    #
    m = len(words)
    n = len(words[0]) if m else 0
    if m != n :
        return False
    for i in range(m):
        n = len(words[i])  #  theoretical length of i-th col & row
        col = 0  # cnt for actual length of i-th col
        # 计算i-th列长度
        for j in range(m):
            # 如果words[j]在i-th 列有元素则该列长度+1，否则退出循环
            if i+1 > len(words[j]):
                break
            col += 1
        # if actual len == theoretical len,continue
        if col != n:
            return False
        # check on a diagonal symmetry
        for j in range(n):
            if words[i][j] != words[j][i]:
                return False
    return True
def validWordSquare2(words):
    """
    :type words: List[str]
    :rtype: bool
    """
    m = len(words)
    n = len(words[0]) if m else 0
    if m!=n:
        return False
    # 对每个行word检查对应列单词长度和对应位置元素是否相同
    for i in range(m):
        # len(words[i])=行单词长度=列单词长度
        for j in range(len(words[i])):  # 此处后不必计算每列长度在单独比较
            if i+1 > len(words[j]) or words[i][j] != words[j][i]:
                return False
    return True
