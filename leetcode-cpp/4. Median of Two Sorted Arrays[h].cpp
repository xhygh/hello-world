/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

tags: binary search, array, D&C;
*/


/****************************
解题思路：

找第K个元素，由时间复杂度约束可知用二分法。

两个有效区间m+n>K，否则不会有第K个元素，两种情况：
1.m,n>=k/2. 因为二分法我们每次可以排除K前有效的元素的一半，所以在这种情况下，如果A[k/2]<B[k/2]又有序，那么A[K/2]的元素肯定是在K之前的元素，
毕竟他比另一个K/2个元素中最大的还小，那两者合并成一个的时候，他的元素肯定都在K之前。反之同理。如果是A[k/2]=B[k/2]，因为一个idx只能放一个元素，
所以两个相同的元素也分前后，所以随便归于之前的两种情况中的一种即可。
2.m或n<k/2，此时一个数组的有效区间的长度小于k/2，如此另一个有效区间必然>看k/2否则没有第k个元素。此时较长的数组的前k/2个元素肯定需要排除，
因为较长数组的前k/2个元素加上较短数组的所有元素都不够K，也就是说由他俩组成的区间内是不会有第K个元素的；
或者换种想法，较长数组要有K/2+其后SOME+较短数组元素才能找到第K个元素，其后SOME元素肯定大于前K/2个元素，所以前K/2个元素肯定不包含第K大的元素。

每次排除前K/2个元素，更新数组的有效区间开始位置以及K，因为前面减少了K/2个元素，所以K=K-K/2。如此逐渐逼近Kth。最后几步几乎就是1个元素1个元素的排除，
当K==1时，只要比较两个数组的头元素大小即可，K起到一个计数作用，前面减少几个，K就减少多少。注意K和下标的关系。
代码里使用K/2-1是因为防止下标溢出，而K=2时不会溢出。而A.begin+K/2-1如果大于等于A.size可以启用上面的情况2处理。-1也是考虑到Kth和index的关系。
-------------------------------
2080 / 2080 test cases passed.
Status: Accepted
Runtime: 32 ms
96.76%
时间复杂度O(log(n+m))，空间复杂度O(1)
***************************/
class Solution {
public:
    double findKth(vector<int>& A, vector<int>& B, int A_head, int B_head, int k) {
        //参数k表示第k个元素，换算未下标是k-1
        // 边界情况，任一数列为空
        if (A_head >= A.size()) {
            return B[B_head + k - 1];
        }
        if (B_head >= B.size()) {
            return A[A_head + k - 1];
        }
        // 递归基，k等于1时，两个数组的头节点最小的即为所求
        if (k == 1) return min(A[A_head], B[B_head]);
        //一般情况
        //比较A[k/2]与B[k/2],或者其中一个不够长
        int Ak = A_head + k/2 - 1 >= A.size()?INT_MAX:A[A_head + k/2-1];
        int Bk = B_head + k/2 - 1 >= B.size()?INT_MAX:B[B_head + k/2-1];
        if(Ak <= Bk)
            return findKth(A,B,A_head+k/2,B_head, k-k/2);
        else
            return findKth(A,B,A_head,B_head+k/2, k-k/2);
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double ret;
        
        if (sum & 1) {
            ret = findKth(nums1, nums2, 0, 0, sum / 2 + 1);
        } else {
            ret = ((findKth(nums1, nums2, 0, 0, sum / 2)) +
                    findKth(nums1, nums2, 0, 0, sum / 2 + 1)) / 2.0;
        }
        return ret;
    }
};
