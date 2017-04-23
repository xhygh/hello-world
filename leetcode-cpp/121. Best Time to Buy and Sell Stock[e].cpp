/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
tags:array,DP;53E,122E,123h,188h,309m
*/

/*****************
solution:
便利序列，记录最小值，以及最大差价
对于每个元素，考虑其与min之差和profit的大小关系，更新profit，
然后更新min

200 / 200 test cases passed.
Status: Accepted
Runtime: 6 ms
45.06%
O(n),O(1)
****************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int mmin = prices[0];
        int profit = 0;
        
        for(int i=1;i<prices.size();++i){
            profit = max(profit,prices[i]-mmin);
            mmin = min(prices[i],mmin);
        }
        return profit;
    }
};
