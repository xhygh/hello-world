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
282 / 282 test cases passed.
Status: Accepted
Runtime: 102 ms
*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        
        //建立hashmap，把所有可能的有序2数字对的index存入hashmap
        unordered_map<int,vector<vector<int>>> hashmap;
        for(int a=0;a<nums.size()-1;++a){
            for(int b=a+1;b<nums.size();++b){
                vector<int> v = {a,b};
                hashmap[nums[a]+nums[b]].push_back(v);
            }
        }
        
        //开始2数字对凑成4数字对，注意是先后有序的a<b<c<d 且都是index
        for(int c = 0;c<nums.size()-1;++c){
            for(int d = c+1;d<nums.size();++d){
                const int key = target - nums[c]-nums[d];
                //如果key不存在则继续循环下一个
                if(hashmap.find(key)==hashmap.end()) continue;
                //如果存在，顺序满足则存入res
                const auto& tmpv = hashmap[key];
                for(int k=0;k<tmpv.size();++k){
                    if(c<=tmpv[k][1]) continue;
                    res.push_back({nums[tmpv[k][0]],nums[tmpv[k][1]],nums[c],nums[d]});
                }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
        
        
    }
};
