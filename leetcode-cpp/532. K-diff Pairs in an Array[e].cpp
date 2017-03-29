/*
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].
Subscribe to see which companies asked this question.


tags:two pointers,array;530e
*/

/*********************
解题思路：
这道题类似之前的一道两数之和等target的题目，那道题目，可以使用hashmap可以先排序。
我遵循这个算法。
首先对数组进行排序，固定i，遍历i之后的j，i和j可以跳过重复的，否则就最后使用unique去重。
72 / 72 test cases passed.
Status: Accepted
Runtime: 43 ms
48.26%
时间复杂度o(n^2),空间复杂度O(1)
**********************/


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();++i){
            int j=i+1;
            while(nums[i+1]==nums[i]) i++;//到最后一个相同的元素
            for(;j<nums.size();++j){
                
                if(nums[j]-nums[i]>k) break;//因为有序，所以最小的相减都比k大那就不用说了，继续更新i
                else if(nums[j]-nums[i]==k) {
                    cnt++;
                    break;//因为有序，不重复基数的话，记1次，就下一个i
                }
                else
                    while(nums[j+1]==nums[j]) ++j;//j+1==j的话就后移
                
            }
            
        }
        return cnt;
    }
};

/***************************
解题思路：
如果一个数组中的两个数之差为指定数值，那么遍历"一半"之后，另一半可以配对的，就直接在map里找就行，有和他能配对的就算。
由于set有无重复性，所以用set记录被减数，即较小的那个，当然也可以记录较大的那个。


72 / 72 test cases passed.
Status: Accepted
Runtime: 35 ms

81.26%
时间复杂度O(n),空间复杂度o(n)
****************************/


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        if(k<0) return cnt;
        
        unordered_map<int,int> val_idx;
        unordered_set<int> smaller;
        for (int i=0;i<nums.size();++i){
            if(val_idx.count(nums[i]-k))  smaller.insert(nums[i]-k);
            if(val_idx.count(nums[i]+k))  smaller.insert(nums[i]);
            val_idx[nums[i]] += 1; //记录idx主要是证明该val出现过，当它的另一半与k作用找到该val，count！=0，即记录较小值。
        }
        return smaller.size();
    }
};
