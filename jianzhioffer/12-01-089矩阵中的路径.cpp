/*****
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

*******/


/********
不要想得很困难，按照思路吧代码写出来就行。
首先想，矩阵中任选一个元素作为起点找strpath。
假设矩阵某个元素是字符c，且当前需要找的目标字符是str[i],如果str[i]== c，那么就要寻找c相邻的四个格子是否有str[i+1]。
重复这个过程知道所有字符找到即str到达'\0'，return true。
否则由于回溯法的递归特性，路径被看做栈，当已经找到了n个str字符，但是str[n-1]周围找不到第n+1个字符即str[n]的时候，
退回路径到第n-1个字符，即str[n-2]，重新寻找第n个字符即str[n-1]。
另外，为了保证不进入已经查找过的格子，需要定义一个矩阵大小的visited标志矩阵记录状态。每个元素的visited状态随时更新，退回时，也需要回复false。

运行时间：3ms
占用内存：496k

*********/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
    	//检查输入数据是否符合规范
        if(matrix==nullptr || rows<1 || cols<1 || str==nullptr)
            return false;
        
        //设置标志矩阵并初始化，记录矩阵元素是否被visit
        bool *visited = new bool[rows*cols];
        memset(visited,0,rows*cols);
        
        //设置变量记录目前目标字符是str的第几个
        int chnb = 0;
        
        //遍历矩阵元素，以每个元素为起始，寻找str路径
        //如果找到了return true
        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                if(haspathcore(matrix,rows,cols,r,c,str,chnb,visited))
                    return true;
            }
        }
        delete[] visited;
        return false;
    }
    
    bool haspathcore(const char* matrix, int rows,int cols,int r,int c,const char* str,int chnb,bool* visited){
        //如果找到了最后一个字符
        if(str[chnb]=='\0')
            return true;//唯一能给出haspath=true的情况
        
        //设置标志位，记录是否走通
        bool haspath = false;
        
        //如果未出界，矩阵该处元素等于str当前元素，且该处矩阵元素未被访问过
        if(r<rows && c<cols && r>=0 && c>=0
           && matrix[r*cols+c]==str[chnb] 
           && visited[r*cols+c]==false){
            visited[r*cols+c] = true;//更新当前元素访问状态
            ++chnb;//更新下一个目标字符的序号
            haspath = haspathcore(matrix,rows,cols,r+1,c,str,chnb,visited) 
                || haspathcore(matrix,rows,cols,r,c+1,str,chnb,visited)
                || haspathcore(matrix,rows,cols,r-1,c,str,chnb,visited)
                || haspathcore(matrix,rows,cols,r,c-1,str,chnb,visited);
            if(!haspath){
                --chnb;//如果在该元素下没有走通
                visited[r*cols+c]=false;//当前元素访问状态恢复false
            }
        }
        return haspath;
    }


};
