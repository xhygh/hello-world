/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 

*/

/*********
想办法把每次的选择变成不相交的情况，右上角和左下角，因为左上角，右下角往两边走的条件都是一样的，中间的更麻烦。
只有右上角和左下角，一大一小两种情况。
例如右上角开始，tmp>target证明target在tmp左面，不在tmp的列，如此排除一列，
同理，如果tmp<target那么target不在tmp那一行，只能往下，如此排除一行。
O(mn),O(1)
*********/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return false;
        int m = array.size();
        int n = array[0].size();
        int tmp = array[0][n-1];  //右上角
        
        for(int i=0,j=n-1;i<m&&j>=0;){
            if(tmp==target)
                return true;
            else if(tmp>target)
                --j;
            else
                ++i;
            tmp = array[i][j];//更新对比元素
        }
        return false;
    }
};
