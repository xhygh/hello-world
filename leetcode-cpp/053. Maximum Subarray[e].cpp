/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

tags:array,DP,DC;121E,152M
*/

/*******************
SOLUTION:
现在在n个连续数据中找出其sum最大的连续子序列，不会，考虑n-1，不会，……，考虑n=1,opt(1)即[0,1)个中最大和子序列，
opt(1)=nums[0],
opt(2),nums[1]加入opt(1)，或者重新开始一个子序列，
判断条件：opt(1)*nums[1]>opt(1)则opt(2)=opt(1)*nums[1],否则opt(2)=nums[1],
但是上面的递推式有问题，一时的降低不能代表之后不能逆袭，所以，这个判断条件不对。
考虑是否要重开子序列的时候需要考虑，对于当前的元素，什么是有害的，无用的，即已有子序列sum<=0，
可以如此考虑，一个连续的子序列，如果想其中的连续子序列sum更大，需要丢弃左右两端<=0的数据。
如此，递推式为：
opt(2) = opt(1)>0?opt(1)+nums[1]:0+nums[1],
opt(i) = opt(i-1)>0?opt(i-1)+nums[i]:0+nums[i]
如此可以得到每个元素与其之前的连续子序列的最大和了。找到其中最大的即可。

有时候我们不能直接用DP解决整个问题，但是我们可以用DP得到备选解。

202 / 202 test cases passed.
Status: Accepted
Runtime: 9 ms
57.68%
O(n),O(1)因为只记录上一个长度序列的最大连续子序列和，所以一个额外空间即可。
**********************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int opt = nums[0];//记录[0,i]中的最大连续子序列和
        int maxopt = opt; //记录n个元素中的最大连续子序列之和
        for(int i=1;i<n;++i){
            opt = opt>0?opt+nums[i]:0+nums[i];//记录当前长度的最大连续子序列和，供给下一次使用
            //opt = max(opt+nums[i],0+nums[i]);  计算数值上等价于上一句，因为opt>0是=时……
            maxopt = max(maxopt,opt);//记录最大连续子序列
        }
        return maxopt;
    }
};
