/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

Subscribe to see which companies asked this question.
 tags：array, two pointers
 21e
*/


/****************************

解题思路：

如果是array，如果从前面开始调整的话，插入数据的时候，
nums1中的靠后的数据都要向后移动，为了防止多次移动，
考虑从m+n-1处开始填入数据，如此就是从后向前排列数据，
原顺序为从小到大，反向即从大到小。


问题：nums1 vector.size()>m+n,还是vector.capation()>m+n ?
本题默认是size()>m+n，所以情况和array相同


59 / 59 test cases passed.
Status: Accepted
Runtime: 6 ms
时间复杂度O(max(m+n)),空间复杂度O(1)
********************************/



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int rear = m+n-1;
        int i = m-1;
        int j = n-1;
        for(;i>=0 && j>=0;)
            nums1[rear--] = nums1[i]>=nums2[j]?nums1[i--]:nums2[j--];
        //不用检查i，如果i>0，那么剩下的都是最小的，不用动，只有nums2里面的需要移入nums1
        for(;j>=0;) nums1[rear--] = nums2[j--];  //m=0,n!=0时这个也work，相当于nums1放完,nums2有剩余
    }
};
