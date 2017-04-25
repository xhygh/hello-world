/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

tags:array,DP;121e,122e,188h
*/

/************************
solution:
121e就是在1-n天内找到最大的利润，本题是在1-n天内找到和最大的两个利润，或者最大的一个利润.
本题是在1-n中找到和最大的两个差价或者一个最大的差价。
可以吧1-n分为左右两部分，左部分最大值+右部分最大值即为所求。
对于每个元素都可以作为一个切割点，从左到右遍历数组，计算当前元素和之前最小值的差价，得到元素[0,i]区间内的最大profit;
从右到左遍历数组，计算右侧最大值和当前元素的最大差价，最后得出l[i]+r[i]最大的profit。
trick：第二次遍历的时候，记录bestprofit=max(bestprofit,sell-prices[j]+l[j])即比较已经得到的左右最大值和当前元素的左右最大值中的最大值

198 / 198 test cases passed.
Status: Accepted
Runtime: 6 ms
55.54%
O(n),O(n)
************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        
        int buy = prices[0];
        vector<int> profit(prices.size());
        for(int l=1;l<prices.size();++l){
            profit[l] = max(profit[l-1],prices[l]-buy);
            buy = min(buy,prices[l]);
        }
        
        int sell = prices[prices.size()-1];
        int best = 0;
        for(int r=prices.size()-2;r>=0;--r){
            best = max(profit[r]+sell-prices[r],best);
            sell = max(prices[r],sell);
        }
        
        return best;
    }
};
