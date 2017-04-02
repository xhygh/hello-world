/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the absolute 
difference between i and j is at most k.

给出一个数组，找idx不同的相同元素，如果有，看两者idx是否差值k以内，是return true
tags:array,hash table;217e,220e
*/



/*************************
solution:
hash table 遍历vector，如果该元素第一次出现或者与之前的相同元素idx间相差大于k，则存入/覆盖原idx；
如果与之前出现过元素的idx之差<=k返回true；
/************注意，本题讨论 重复是可以多次重复的，这个要和面试官问好****************/
23 / 23 test cases passed. 
Status: Accepted 
Runtime: 26 ms 74.89%
时间复杂度O(n)，空间复杂度O(n)
************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k<=0) return false;  //边界情况
        
        //一般情况
        unordered_map<int,int> elemIdx;
        for(int i=0;i<nums.size();++i){
            if (elemIdx.find(nums[i])==elemIdx.end()||abs(elemIdx[nums[i]]-i)>k) //如果没找到
                elemIdx[nums[i]]=i;//存入该元素
            else
                return abs(elemIdx[nums[i]]-i)<=k;
        }
        return false;       
    }
};



/**********************
solution：
因为相同元素的距离不能大于k，所以只要保留k长度的元素即可。
首先在无重复条件下，存入k+1个元素之后，表示这k+1个元素中没有重复的。
此时i>k，因为i==k的时候存入了k+1个元素，删除这k+1个元素的第一个即i-k-1（反正不是重复的）。
再插入的时候依旧考察无重复条件，下一个循环依然先删除保留的第一个元素。
**********************/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /**************
        set的特点是，如果已经包含了元素e，那么再次s.insert(e)的返回值.second==false，
        因为同样的元素不许再次插入。
        **************/
        set<int> elem;
        for(int i=0;i<nums.size();i++){
            if(i>k)//可以进行第一次比对了,已经存入k+1个元素了
                elem.erase(nums[i-(k+1)]);//因为idx不能相同，所以k+1范围外的元素都没用了，可以删除
            if(!elem.insert(nums[i]).second) return true;
        }
        return false;
    }
};
