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

/****************************
三元组不可重复，但是三元组内的数字可以重复，如此可以先确定第一个数字，这个数字是S中所有数字去重后的所有可能。
剩下两个数字就从排除掉第一个数字之后的S中（不是去重的S）选取即2SUM问题，可以看ID=1的题目，为了方便先对S进行排序。
（1）	对S排序；
（2）	遍历S的每种数字为a；
（3）	a之后的所有数字即为2SUM问题；
（4）	排序后我们可以假设a<b<c，如此2SUM使用围堵方法，b从a后增加，c从尾数减小；
（5）	如果a+b+c>0，证明需要减小三者之后，a固定，b只能增加，所以令c左移减小；同理如果a+b+c<0，证明需要增加三者之和，
      只能b右移增加；a+b+c=0的情况加入result。
（6）	如果中途不考虑去重问题就返回之前去重。
代码1
313 / 313 test cases passed.
Status: Accepted
Runtime: 135 ms
时间复杂度O(n^2),空间复杂度O(1)
****************************/
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
                    while(j<k && *k==*(k+1)) --k;  //吧中间相同的数据都跳过
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



/************************
上面程序的index版本
代码2
313 / 313 test cases passed.
Status: Accepted
Runtime: 189 ms
11.57%
时间复杂度O(n^2),空间复杂度O(1)
*************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()<3) return result;   //长度不够就返回空
        sort(nums.begin(), nums.end());  //数组排序
        const int targ = 0; //定义常数和
        
       	for (int i = 0; i< nums.size() - 2; ++i){
	       
	        auto j = i + 1;
	        if (i > 0 && nums[i] == nums[i - 1]){

	        	continue;  //由于已排序，所以衡量过的数字不再衡量
		}
		auto k = nums.size() - 1;
	        while (j<k){
	        	if (nums[i] + nums[j] + nums[k] < targ){ //如果比目标数值小，则往大里调
	        		j++;
	        		while (j<k && nums[j] == nums[j - 1]) ++j;  //吧中间相同的数据都跳过
	        	}
	        	else if (nums[i] + nums[j] + nums[k] > targ){
	        		k--;
	        		while (j<k && nums[k] == nums[k + 1]) --k;  //吧中间相同的数据都跳过
	        	}
	        	else{
	        		result.push_back({ nums[i], nums[j], nums[k] });
	        		++j;
	        		--k;
	        		while (j<k && nums[k] == nums[k + 1] && nums[j] == nums[j - 1]) j++;
	        	}
	        }
			
		}
		return result;
    }
};


/**********************

代码3
313 / 313 test cases passed.
Status: Accepted
Runtime: 105 ms
时间复杂度O(n^2),空间复杂度O(1)
就是把代码1的结构调整了一下，i在后面才移动去重，如此就不需要i>nums.begin()
***********************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()<3) return result;   //长度不够就返回空
        sort(nums.begin(), nums.end());  //数组排序
        const int targ = 0; //定义常数和
        
        auto last = nums.end();
        for (vector<int>::iterator i = nums.begin(); i<last-2; ++i){
            auto j = i+1;
            auto k = last - 1;
            while(j<k){
                int sum = *i + *j + *k;
                if (sum < targ){ //如果比目标数值小，则往大里调
                    j++;
                }
                else if (sum > targ){
                    k--;
                }else{
                    result.push_back({*i,*j,*k});
                    ++j;
                    --k;
                    while(j<k && *j==*(j-1)) j++;
                    while(j<k && *k==*(k+1)) k--;
                }
            }

            while (i<nums.end() && *i == *(i+1)) i++;  //由于已排序，所以衡量过的数字不再衡量
        }
        return result;
    }
};
