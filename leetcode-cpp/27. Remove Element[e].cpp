/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
Hint:

Try two pointers.
Did you use the property of "the order of elements can be changed"?
What happens when the elements to remove are rare?
tags:array,tow pointers;
26e,203e,283e
*/

/*********************
解题思路：
不需要排序，所以只要把不删除的元素从0开始放，删除的元素覆盖掉即可。
113 / 113 test cases passed.
Status: Accepted
Runtime: 3 ms
78.54%
*********************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nb = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val) nums[nb++] = nums[i];//将保留的元素从头放置，最多是覆盖自己，不会影响其他元素
        }
        //nums.erase(nums.begin()+nb,nums.end());//删除[,)的元素
        return nb;//因为上面是nb++，所以已经加+1了
    }
};

/**************************
解题思路：
利用C++标准库函数remove和distance
remove(.begin(),.end(),val)从[.begin(),.eng())中将非val的放前面，等于val的放后面，返回第一个val的迭代器。
distance(.begin(),.end()),计算[.begin(),.eng())间的元素数目
113 / 113 test cases passed.
Status: Accepted
Runtime: 3 ms
78.54%
******************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(),remove(nums.begin(),nums.end(),val));
    }
};

/**************************
解题思路：

先排序，如此如果nums中存在val，那就会相邻排列，找到头尾迭代器位置，区间删除，返回nums.size()

113 / 113 test cases passed.
Status: Accepted
Runtime: 6 ms
17.69%

时间复杂度和空间复杂度看排序算法了

      最差时间分析	平均时间复杂度	稳定度	空间复杂度
冒泡排序	O(n2)	      O(n2)	      稳定	  O(1)
快速排序	O(n2)	      O(n*log2n)	不稳定	O(log2n)~O(n)
选择排序	O(n2)	      O(n2)	      稳定	  O(1)
二叉树排序	O(n2)	     O(n*log2n)	不一顶	  O(n)
插入排序  O(n2)	      O(n2)	      稳定	O(1)
堆排序	O(n*log2n)	O(n*log2n)	  不稳定	O(1)
希尔排序	O	          O	        不稳定	    O(1)
******************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        //如果有val出现在nums里
        for(vector<int>::iterator i=nums.begin(),b;i<nums.end();++i){
            if((i==nums.begin()||*i!=*(i-1)) && *i==val) b=i; //考虑首元素没有前一个
            if((i==nums.end()-1||*(i+1)!=*i) && *i==val) {//考虑尾元素没有后一个
                nums.erase(b,++i);
                return nums.size();
            }
        }
        //如果没有val出现在nums
        return nums.size();
    }
};
