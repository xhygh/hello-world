/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
-----------------------------

tags:array,hash table two pointers
1[e],15[m]
*/

/****************************************************
先排序，然后左右顺序夹逼，和3sum一样，中间跳过重复的数字。
时间复杂度O(n^3),空间复杂度O(1)
accept 42ms
****************************************************/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());

		auto last = nums.end();
		for (auto i = nums.begin(); i < last - 3; ++i){
		    //重复的i跳过
			auto tmp = i;
			if (i>nums.begin() && *i == *(i - 1)) continue;
			
			for (auto j = tmp + 1; j < last - 2; ++j){
				auto k = j + 1;
				if (j>tmp + 1 && *j == *(j - 1)) continue;  //重复的j跳过
				auto l = last - 1;
				while (k < l){
					if (*tmp + *j + *k + *l < target){
						++k;
						while (k < l &&*k == *(k - 1)) ++k;
					}
					else if (*tmp + *j + *k + *l > target){
						--l;
						while (k < l &&*l == *(l + 1)) --l;
					}
					else{
						result.push_back({ *tmp, *j, *k, *l });
						++k;
						--l;
						while (k < l && *k == *(k - 1) && *l == *(l + 1)) ++k;

					}
				}
			}//for
		}//for
		sort(result.begin(), result.end());
		return result;
	}
};
/*方法2：Mapping
使用一个hashmap缓存2个数之和。
时间复杂度O(n^2),最差情况O(n^4),空间复杂度O(n^2)因为保存的2个数是2个for循环
*/
