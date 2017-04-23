/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). However, 
you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).


tags:array,greedy;121e,123h,188h,309m
*/

/*****************
solution:可以多次交易（一次买卖算一次交易），但买之前必须卖掉。
121e是找最大差值，本体是将所有差值找到并求和。
greedy方法。
因为题目要求不可以同时进行多个交易，所以正确来讲，因是找到所有局部最大值和他之前的局部最小值求差，但是这样程序不好写。
但是因为局部最大和局部最小之间都是上升的，所以后面一个elem-前面一个elem得到这一段的差值，按理说是多次交易了，但是多次交易融合成一次交易。
算是一个trick

198 / 198 test cases passed.
Status: Accepted
Runtime: 6 ms
42.23%
O(n),O(1)
*****************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int profit = 0;
        for(int i=1;i<prices.size();++i)
            profit += max(prices[i]-prices[i-1],0);
        return profit;
    }
};
