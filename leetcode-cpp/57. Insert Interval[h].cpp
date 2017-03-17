/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

tags:array,sort;56M
*/

/*****************************
解题思路：
原本序列中的间隔都是不重叠的，加入的是【可能】重叠的。
因为是有序序列，所以某个间隔a.end < newInterval.start之前的间隔
以及a.start > newInterval.end之后的都不必考虑，直接加入res；
若而上面之外那些情况的间隔，a与newInterval有重叠则更新newInterval:newInterval.start = min(a.start,newInterval.start)
newInterval.end=max(c.end,newInterval.end)重叠这一段的间隔都被抹掉，在新集合中，以newInterval取代。
如果最后newInterval是res中排在最后的，那么之前已经遍历过intervals,所以单独再res.push_back(newInterval)并返回res即可。
152 / 152 test cases passed.
Status: Accepted
Runtime: 13 ms
78.78%
时间复杂度O(n)，空间复杂度O(n)
********************************/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;

        //newInterval前后有其他区间
        for(int i=0;i<intervals.size();++i){
            if(intervals[i].end < newInterval.start) res.push_back(intervals[i]);
            else if(intervals[i].start > newInterval.end) {
                res.push_back(newInterval);
                while(i<intervals.size()) res.push_back(intervals[i++]);
                return res; // 因为是有序的，所以小的start比newInterval.end大，大的自然更大，不必比较直接加入res
            }
            else{//算上边界，有重叠的情况，更新newInterval,忽略重叠区域的原间隔
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            
        }
        //无论intervals里有多少排在nerInterval之前的间隔newInterval即最后一个间隔,这也包含了intervals.size()==0的情况
        res.push_back(newInterval);
        return res;
    }
};


/******************************
解题思路：
迭代器遍历intervals,end<newInterval的不动，
有重叠部分的原区间删除并更新newInterval,
start>newInterval.end的先把newInterval插入intervals，然后返回intervals.
如果出现newInterval是排列在最后的区间则，之前的for循环已经遍历intervals,
所以在单独讲newInterval插入intervals,返回intervals.

152 / 152 test cases passed.
Status: Accepted
Runtime: 72 ms
8.72%
时间复杂度O(n)，空间复杂度O(1)
*******************************/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;

        //newInterval前后有其他区间
        for(auto i=intervals.begin();i<intervals.end();){
            if(i->end < newInterval.start) {
                i++;
                continue;
            }
            else if(i->start > newInterval.end) {
                intervals.insert(i, newInterval);
                return intervals; // 因为是有序的，所以小的start比newInterval.end大，大的自然更大，不必比较直接加入res
            }
            else{//算上边界，有重叠的情况，更新newInterval,忽略重叠区域的原间隔
                newInterval.start = min(newInterval.start, i->start);
                newInterval.end = max(newInterval.end, i->end);
                i = intervals.erase(i);//返回i++位置迭代器，有重叠的原区间删除
            }
            
        }
        //无论intervals里有多少排在nerInterval之前的间隔newInterval即最后一个间隔,这也包含了intervals.size()==0的情况
        intervals.insert(intervals.end(),newInterval);
        return intervals;
    }
};
