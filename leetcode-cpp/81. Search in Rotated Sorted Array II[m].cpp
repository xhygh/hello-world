/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.


tags: array, binary search; 33m
*/

/**************************

解题思路：
本题与33m相比只是有一个条件变动的，允许重复元素，如此我们判断有序array的条件就需要更改，因为不适用了。
原本是nums[l]<=nums[m]，这个条件在一些情况小实效，例如[1,1,2,1,1,1,1]，
所以可以分为两种情况,情况1还适用原来的部分条件nums[l] < nums[m]；
情况2，nums[l] = nums[m]，此时可以领l++，一直到nums[l] != nums[m],此时可以看看是否符合条件nums[l] < nums[m]，不符合就不是升序，
当然也有可能知道l==m都是nums[l] = nums[m]，这种情况当然是最不好的。


273 / 273 test cases passed.
Status: Accepted
Runtime: 6 ms
36.52%
时间复杂度O(log n),空间复杂度O(1)
时间复杂度最差是O(n)例如[1,1,1,1,1,1,1,1,1],target=0，遍历得到false
时间复杂度最好是O(1)
*************************/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        
        int l = 0, r = nums.size()-1, m = 0;
        while(l <= r){
            m = (r+l)/2;
            if (nums[m] == target) return true;
            else if(nums[l]<nums[m]){ //肯定左边有序
                if(nums[l]<=target && target <nums[m]) r = m-1;
                else
                    l = m+1;
            }
            /********************以下是在33m基础上增加的，其他都不变**********************/
            else if(nums[l]==nums[m]){//不能确定是否左边有序
                while(l<=m && nums[l]==nums[m]) ++l;//一直找到不等于nums[m]的元素,或者直接进入右边部分
            }
            /*************************************************************************/
            else{//左边确实无序，右边有序
                if(nums[m]<target && target<=nums[r]) l=m+1;
                else
                    r = m-1;
            }
        }
        return false;
    }
};

/**********************
解题思路：
这版本仅仅是与上面的边界条件不同.

273 / 273 test cases passed.
Status: Accepted
Runtime: 6 ms
36.52%

时间复杂度O(log n),空间复杂度O(1)
时间复杂度最差是O(n)例如[1,1,1,1,1,1,1,1,1],target=0，遍历得到false
时间复杂度最好是O(1)
*************************/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        
        int l = 0, r = nums.size(), m = 0; //区间是[left,right)
        while(l < r){
            m = (r+l)/2;
            if (nums[m] == target) return true;
            else if(nums[l]<nums[m]){ //肯定左边有序
                if(nums[l]<=target && target <nums[m]) r = m;  //此处由r=m-1变为r=m
                else
                    l = m+1;
            }
            else if(nums[l]==nums[m]){//不能确定是否左边有序
                while(l<=m && nums[l]==nums[m]) ++l;//一直找到不等于nums[m]的元素,或者直接进入右边部分
            }
            else{//左边确实无序，右边有序
                if(nums[m]<target && target<=nums[r-1]) l=m+1;  //此处nums[r]变为nums[r-1]，因为r不在考虑范围内
                else
                    r = m;//此处由r=m-1变为r=m
            }
        }
        return false;
    }
};

//-----------------不同写法------------------
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        
        int l = 0, r = nums.size(), m = 0;
        while(l < r){
            m = (r+l)/2;
            if (nums[m] == target) return true;
            else if(nums[l]<nums[m]){ //肯定左边有序
                if(nums[l]<=target && target <nums[m]) r = m;
                else
                    l = m+1;
            }
            else if(nums[l]>nums[m]){//左边确实无序，右边有序
                if(nums[m]<target && target<=nums[r-1]) l=m+1;
                else
                    r = m;
            }
            else {//不能确定是否左边有序
                while(l<=m && nums[l]==nums[m]) ++l;//一直找到不等于nums[m]的元素,或者直接进入右边部分
            }
        }
        return false;
    }
};
