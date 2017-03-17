/*
Given a sorted array, remove the duplicates in place such that 
each element appear only once and return the new length.

Do not allocate extra space for another array, 
you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, 
with the first two elements of nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the new length.


tags:array, two pointer;27e
*/
/******************************
解题思路：
两个迭代器，b指向元素a首次出现位置，e指向a最后一次出现的位置。
大致两种情况：1没有重复的，2有重复的。

1.没有重复的：b,e同时移动，情况1:e+1<nums.end()&&*e==*(e+1),情况2：e+1<nums.end()

2.有重复的：e+1<nums.end() && *e==*(e+1)时，一直找到最后一个重复的元素位置，此时使用nums.erase(b,e)删除[b,e)间元素，并返回e指向的元素，
所以b = e = nums.erase(b, e)+1这样状态又回到我们从1开始分析的时候了，循环考虑e<nums.end()即可。

161 / 161 test cases passed.
Status: Accepted
Runtime: 49 ms
13.24%
时间复杂度O(n)，空间复杂度O(1)这是不算排序和删除的复杂度
【要注意题目条件，已经给出排序后的，所以不要在排序了，还有注意边界条件，耗了好久】
***********************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<1) return 0;        
        vector<int>::iterator b=nums.begin(),e=nums.begin();
        
        while(e<nums.end()){
            if((e+1<nums.end() && *e!=*(e+1)) || e+1 >= nums.end()) b=++e; //没有重复的两者同时后移
            else{
                while(e+1<nums.end() && *e==*(e+1)) e++;//有重复的，e一直挪动到最后一个重复的位置
                b = e = nums.erase(b, e)+1;//删除区间[b,e),因为返回的是e即去重后的数字，所以要+1，得到下一个数字
            }
        }
        return nums.size();
    }
};

/***************************
解题思路：
充分利用C++标准库函数
distance(.begin(),.end())返回[.begin(),.end())间的元素数目
unique(.begin(),.end())将[.begin(),.end())间重复的元素移到末尾，返回不重复元素的.end()

161 / 161 test cases passed.
Status: Accepted
Runtime: 25 ms
95.28%
******************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(),unique(nums.begin(),nums.end()));
    }
};

/*****************************

解题思路：
因为是有序的vector<int>，所以可以采用从头排序方法。

idx=0，从1开始遍历vector，如果nums[i]>nums[idx],nums[idx]=nums[i]，因为如果有重复的就覆盖掉重复的，
没有重复的就在自己本来的位置，不会覆盖到后面。最后返回idx+1即可

161 / 161 test cases passed.
Status: Accepted
Runtime: 29 ms
53.28%
********************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int idx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[idx]) nums[++idx] = nums[i]; //idx原本就比i小，所以idx不会大于i
        }
        return idx+1;
    }
};
