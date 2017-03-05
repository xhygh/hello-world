/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

tags: array, two pointers
similar:1. Two Sum[e],16. 3Sum Closest[m],18. 4Sum[m],

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()<3) return result;   //长度不够就返回空
        sort(nums.begin(), nums.end());  //数组排序
        const int targ = 0; //定义常数和
        
        auto last = nums.end();
        for (vector<int>::iterator i = nums.begin(); i<nums.end()-2; ++i){
            if (i > nums.begin() && *i == *(i-1)) continue;  //由于已排序，所以衡量过的数字不再衡量
            auto j = i+1;
            auto k = last - 1;
            while(j<k){
                if (*i + *j + *k < targ){ //如果比目标数值小，则往大里调
                    j++;
                    while(j<k && *j==*(j-1)) ++j;  //吧中间相同的数据都跳过
                }
                else if (*i + *j + *k > targ){
                    k--;
                    while(j<k && *k==*(k+1)) ++k;  //吧中间相同的数据都跳过
                }else{
                    result.push_back({*i,*j,*k});
                    ++j;
                    --k;
                    while(j<k && *k==*(k+1) && *j==*(j-1)) j++;
                }
            }
        }
        return result;
    }
};
