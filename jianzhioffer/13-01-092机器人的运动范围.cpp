/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

*/


/*******


时间限制：1秒 空间限制：32768K
运行时间：1ms
占用内存：368k
*******/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {//与12题极其类似，框架一样
        //检查输入数据边界
        if(threshold<0 || rows<=0||cols<=0)
            return 0;
        
        //设置visited标记矩阵元素访问情况
        bool* visited = new bool[rows*cols];
        memset(visited,0,rows*cols);
        
        //因为00位置肯定可以访问，且不需要找路径，所以，不需要遍历元素，可以直接回溯访问
        int cnt = movecnt(threshold,rows,cols,0,0,visited);
        
        delete[] visited;
        return cnt;
        
    }
    int movecnt(int t,int rows,int cols,int r,int c,bool* visited){
        //所有寻找任务在次函数中完成
        int cnt = 0;//记录本元素位置
        if(check(t,rows,cols,r,c,visited)){
            visited[r*cols+c]=true;//可以访问
            cnt = 1 + movecnt(t,rows,cols,r+1,c,visited)
                +movecnt(t,rows,cols,r-1,c,visited)
                +movecnt(t,rows,cols,r,c+1,visited)
                +movecnt(t,rows,cols,r,c-1,visited);//统计周围
            
        }
        return cnt;//返回当前几点四周的可到达点数量
    }
    //检查是否可以到达，边界，加和，是否访问过
    bool check(int t, int rows,int cols, int r,int c,bool* visited){
        if(r>=0 && r<rows && c>=0 && c<cols
          && (getsum(r)+getsum(c))<=t
          && visited[r*cols+c]==false)
            return true;
        return false;
    }
    int getsum(int idx){//计算加和
        int sum=0;
        while(idx>0){
			sum += idx%10;
            idx/=10;
        }
        return sum;
    }
};
