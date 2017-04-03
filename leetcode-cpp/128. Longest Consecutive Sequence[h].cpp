/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

tags:array,union found;
*/

/******************
solution:
整数无序数组，从中找出一个最长的连续序列，返回它的长度。
hashmap的key存储序列元素，value存储该元素所在序列的长度。
如果该元素不存在，查看他的相邻两个元素是否存在，将其左元素记录的长度记录在left没有元素记录的长度记录在right中。
更新该元素的序列长度left+right+1;
为避免查找hashmap，使用res记录每次加入元素后的最大序列长度，并更新该元素所在序列的两头的元素记录的序列长度。

68 / 68 test cases passed.
Status: Accepted
Runtime: 9 ms
65.84%
时间复杂度O(n)，空间复杂度O(n)
*******************/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> elem;
        for(int i=0;i<nums.size();++i){
            if(elem.find(nums[i])==elem.end()){//如果未存入该元素
                int left = elem.find(nums[i]-1)!=elem.end()? elem[nums[i]-1]:0; //如果有左元素
                int right = elem.find(nums[i]+1)!=elem.end()? elem[nums[i]+1]:0;//如果有右元素
                
                int sum = left+right+1;//计算该元素序列长度
                res = max(sum,res);//更新最大序列长度
                
                elem[nums[i]] = sum;//该元素记录入hashmap
                
                //更新该元素所在序列两头的长度记录
                elem[nums[i]-left] = sum;//更新为当前元素的序列长度
                elem[nums[i]+right] = sum;//更新为当前元素的序列元素长度
            }
            else
                continue;
        }
        return res;
    }
};
