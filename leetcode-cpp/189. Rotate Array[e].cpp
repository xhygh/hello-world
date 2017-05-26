/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]
Hint:
Could you do it in-place with O(1) extra space?

Related problem: Reverse Words in a String II
tags: array;61m;
*/

/*
将数组的右边当K的元素转移到数组前面
solution1：
复制一个副本，cpy其。
33 / 33 test cases passed.
	Status: Accepted
Runtime: 23 ms
O(n),O(n)
33.28%
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()||k<=0) return;
        int n = nums.size();
        //copy it
        vector<int> tmp;
        for(int i=0;i<n;++i){
            tmp.push_back(nums[i]);
        }
        
        //set nums
        for(int i=0;i<n;++i){
            nums[(i+k)%n] = tmp[i];
        }
    }
};

/***************
solution:2

*****************/
