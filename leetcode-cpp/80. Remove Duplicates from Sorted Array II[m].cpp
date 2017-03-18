/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, 
with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.


tags:array, two pointers
*/

/**************************
解题思路：
借用21e题目的array排序方法，由于原数组是已经有序的，所以从第一个元素开始从新排序是可以的。
加上一个cnt记录同一个元素出现的次数，以前不用记录，只要把不同的顺序放入即可，
现在是不同的要放入，相同的如果没超过k次也要放入。
需要注意的是cnt<k且cnt初始值为1，因为不同的放入时已经放入一次了，相同的放入时肯定是之前至少有一次了，所以cnt初始为1。


164 / 164 test cases passed.
Status: Accepted
Runtime: 16 ms
27.63%
时间复杂度O(n),空间复杂度O(1)，原数组遍历。
***************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //空集直接返回0
        if(nums.empty()) return 0;
        
        //如果不是空集
        int idx = 0;
        int cnt = 1;  //要从1开始，不可使0，因为第一个数字直接进入else
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[idx]){
                nums[++idx] = nums[i];
                cnt = 1;
            }
            else if(cnt<2 && nums[i]==nums[idx]){ //不可使cnt<=2那样会多一次
                nums[++idx] = nums[i];
                cnt++;
            }
        }
        return idx+1;
    }
};

/*******************
解题思路：

two pointers的思路，使用b和e两个指针遍历Nums。如果本元素和后一个元素不同且不是末节点，或者就是末节点，b=++e;
否则，如果本元素不是末节点且与后一个元素相同，那么利用while一直找到最后一个相同的元素，
当b和e间的元素数量大于等于k个指定个数时，通过nums.erase(b+k,e+1)，删除多余的元素并且返回新元素的迭代器即e+1，
如此，如果重复的数量不够k个也就不会删除元素了，虽然此时，b!=e,但再次进行时，因为*e!=*(e+1),e指向的还是重复的最后一各元素，所以b=++e。
164 / 164 test cases passed.
Status: Accepted
Runtime: 12 ms
93.51%
时间复杂度O(n),空间复杂度O(1)
*********************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //空集直接返回0
        if(nums.empty()) return 0;
        
        //如果不是空集
        vector<int>::iterator b = nums.begin(), e = nums.begin();
        while(e<nums.end()){
            if((e+1<nums.end() && *e!=*(e+1)) || e+1>=nums.end()) b = ++e; //无重复或者在尾端b和e指向同一个并后移
            else{
                while(e+1<nums.end() && *e==*(e+1)) ++e; //如果有重复的，且e不是末节点，一直找到重复的最后一个节点
                if(e-b > 2-1-1) b=e=nums.erase(b+2,e+1);  //删除[b+2,e+1)间的元素，返回e+1的迭代器即新元素
                //如果不够熟练，不删除b!=e，但是由于*e!=*(e+1),所以b = ++e
            }
        }
        return nums.size();
    }
};
