/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

tags:binary search, array; 81m,153m
*/

/********************
二分查找：
一看到数组本身已经有序，我想你可能反应出了要用二分查找，毕竟二分查找的适用条件就是有序的。那什么是二分查找呢？

二分查找可以解决（预排序数组的查找）问题：只要数组中包含T（即要查找的值），那么通过不断缩小包含T的范围，最终就可以找到它。其算法流程如下：

一开始，范围覆盖整个数组。
将数组的中间项与T进行比较，如果T比数组的中间项要小，则到数组的前半部分继续查找，反之，则到数组的后半部分继续查找。
如此，每次查找可以排除一半元素，范围缩小一半。就这样反复比较，反复缩小范围，最终就会在数组中找到T，或者确定原以为T所在的范围实际为空。
对于包含N个元素的表，整个查找过程大约要经过log(2)N次比较。
要准确实现二分查找，首先要把握下面几个要点：

关于right的赋值
right = n-1 => while(left <= right) => right = middle-1;
right = n => while(left < right) => right = middle;
middle的计算不能写在while循环外，否则无法得到更新。
-----------------------------------------------------

解题思路：
使用二分查找。首先取得mid，判断nums[mid]==target?是则直接返回。
不等则判断左边是否有序，如果左边有序，判断target是否在左边，是则正常二分，否则，target在右边无序处，更新区间；
如果是右边有序，同样与上一步一样操作。

【本题其实就是二分，只不过是通过有序的一边来判断。】
196 / 196 test cases passed.
Status: Accepted
Runtime: 6 ms
50.56%
时间复杂度O(log n)，空间复杂度O(1)

*********************/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int left = 0;
        int right = nums.size() - 1;//开始是[left,right]
        while (left<=right){
            int mid = (right+left) / 2; //向上取整
            if (nums[mid] == target) return mid; //是否在中间
            else if(nums[left]<=nums[mid]){//左边有序
                if (nums[mid] > target && nums[left] <= target)	right = mid - 1;//在左边
                else left = mid+1;//在右边
            }
            else{
                if( nums[mid]<target && nums[right]>= target) left = mid + 1;
              else right = mid-1;
            }
        }

        return -1;
    }
};


/*****************

另一个边界条件版本
*****************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int left = 0;
        int right = nums.size();//开始是[left,right)
        while (left<right){
            int mid = (right+left) / 2; //向上取整
            if (nums[mid] == target) return mid; //是否在中间
            else if(nums[left]<=nums[mid]){//左边有序
                if (nums[mid] > target && nums[left] <= target)	right = mid;//在左边
                else 
                  left = mid+1;//在右边
            }
            else{
                if( nums[mid]<target && nums[right]>= target) left = mid + 1;
              else 
                right = mid;
            }
        }

        return -1;
    }
};
