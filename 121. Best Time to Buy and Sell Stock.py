"""
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
"""

method #1
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices == None or len(prices)==0:
            return 0
        Min = sys.float_info.max
        Max = sys.float_info.min
        profit = 0
        for price in prices:
            if price < Min:
                Min = price
            elif price - Min > profit:
               profit = price - Min
        return int(profit)
        
        
method #2
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        Min = sys.maxint
        Max = -sys.maxint
        profit = 0
        for price in prices:
            Min = min(price, Min)
            profit = max(price - Min, profit)
        return profit
        
            
            
            
