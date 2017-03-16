/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

tags: array,sort
57h,495m
*/

/*******************
解题思路：

先使用sort对intervals.start排序，
因为后面都是前一个和后一个判断前一个能不能半包或者全包前一个，不能就把前一个加入res.
两种交集情况
[[1,2],[1,4]]
[[1,4][2,4]]同上处理
[[1,4],[2,3]]
其实就是前一个end和后一个start，end的关系，
val2.start<=val1.end<val2.end，
val2.end<=val1.end

168 / 168 test cases passed.
Status: Accepted
Runtime: 16 ms
51.59%
********************/

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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()<2) return intervals;
        sort(intervals.begin(), intervals.end(), compare_interval);
        
        Interval tmp=intervals[0];
        for(int i=1;i<intervals.size();){
            if(tmp.end>=intervals[i].start&&tmp.end<intervals[i].end) {//可以合并 前一个半包后一个
                tmp.end = intervals[i++].end;
            }
            else if(tmp.end>=intervals[i].end){//前一个全包后一个
                i++;
            }
            else{//无交集
                res.push_back(tmp);
                tmp = intervals[i++];
            }
        }
        res.push_back(tmp);//加入最后一个不能合并的
        return res;
    }
    
private:
    //sort中的比较函数
    static int compare_interval(Interval val1,Interval val2){
        return val1.start < val2.start;
    }
};
