/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
-----------------
tars: array,two pointers
15. 3Sum[m]
*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        if (nums.size()<3) return result;
        sort(nums.begin(),nums.end());
        
        int tmp = INT_MAX;
        auto last = nums.end();
        for (auto i = nums.begin();i<last-2;++i){
            auto j = i + 1;
            if(i>nums.begin() && *i==*(i-1)) continue; //第一个加数不能重复
            auto k = last-1;
            
            while(j<k){
                //相等直接返回
                if (*i + *j + *k == target) return result;  
                //如果比之前的举例小，就更新result
                if(abs(*i + *j + *k - target) < tmp) {
                    tmp = abs(*i + *j + *k - target);
                    result = *i + *j + *k;     
                }
                //继续寻找,因为相等的直接返回，所以只有不相等的情况
                if (*i + *j + *k<target){
                    ++j;
                    while(j<k && *j==*(j-1)) ++j;
                }
                else if (*i + *j + *k>target){
                    --k;
                    while(j<k && *k==*(k+1)) --k;
                }
            }//while
        }//for
        return result;
        
    }
};
