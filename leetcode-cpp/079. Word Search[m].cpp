/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

tags:array,backtracking;212h
*/

/*********************

solution:
递归遍历整个board，对于board上的每个元素，查周围元素是否符合。
详细过程：
查当前元素是否为第一个字母，然后在其周围查是否存在第二个字母，然后在第二个字母元素周围查找第三个……直到某个字母找不到return false；
因为本题只要求true或者false，所以用||逻辑，只要把查找过的、合格的地方做标记继续往下找即可，不必担心重复等情况。
【注意】*标记本路线经过的元素，但是探查四周之后要恢复本元素数据，不可以*一直替代，防止之后的正确路线由于之前的错误标*导致判错。

87 / 87 test cases passed.
Status: Accepted
Runtime: 36 ms
34.92%
时间复杂度O(n^2),空间复杂度O(1)
*******************/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row=0;row<board.size();++row){
            for(int col=0;col<board[0].size();++col){
                //检查board中的每个元素
				//return isExist(board, word, row, col, 0);不能直接这样，不然首字母不对就直接返回了
				if (isExist(board, word, row, col, 0)) return true;//如果有符合的就返回true
            }
        }
        return false;//【遍历】board没有符合条件的
    }
    
private:
    bool isExist(vector<vector<char>> &board, string word,int row,int col, int elemIdx){
        //递归基
        //都找到了，idx超出word，return true
        if(elemIdx>=word.size()) return true;
        //如果范围超出board（+-1都要查）或者字母不同，return false
        if(row<0||col<0||row>=board.size()||col>=board[0].size()||board[row][col]!=word[elemIdx])
            return false;
        
        //如果未检查完，未超范围，元素==word[elemIdx]
        /***
         * 不可如下：以内如果有两个方向都合适且两个都会用到，||中的顺序会影响判断，提前将一个要用到的标志之后没法用就错误了。
        board[row][col]='*';//标记合格的元素，防止重复查找
        return isExist(board,word,row-1,col,elemIdx+1)||isExist(board,word,row+1,col,elemIdx+1)||isExist(board,word,row,col-1,elemIdx+1)||isExist(board,word,row,col+1,elemIdx+1);
        ***/
        
        char backup = board[row][col];//保存当前元素，之后用于恢复，避免影响之后的判断
        board[row][col]='*';//标记本路线合格的元素，防止重复查找
        bool isexist = isExist(board,word,row-1,col,elemIdx+1)||isExist(board,word,row+1,col,elemIdx+1)||isExist(board,word,row,col-1,elemIdx+1)||isExist(board,word,row,col+1,elemIdx+1);
        board[row][col] = backup;//恢复元素，避免给其他正确路线造成错误，如果不恢复，可能本路线是错误的，其他路线之后用该元素却是*了
        return isexist;
        
    }
    
};

/************************
solution:
同样的思路，比上面的快；

87 / 87 test cases passed.
Status: Accepted
Runtime: 9 ms
87.25%
时间复杂度O(n^2),空间复杂度O(1)
**************************/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int row=0;row<m;++row){
            for(int col=0;col<n;++col){
                //检查board中的每个元素
				//return isExist(board, word, row, col);不能直接这样，不然首字母不对就直接返回了
				if (isExist(board, word.c_str(), row, col)) return true;//如果有符合的就返回true
            }
        }
        return false;//【遍历】board没有符合条件的
    }
    
private:
    int m;
    int n;
    //const char*指针可变，元素不可变，指向常量的可变指针
    bool isExist(vector<vector<char>> &board, const char* word,int row,int col){
        /*递归基*/

        //如果范围超出board（+-1都要查）或者标记过或者首元素不合格，return false
        if(row<0||col<0||row>=m||col>=n||board[row][col]=='\0'||board[row][col]!=*word)
            return false;            
        //都找到了，而且本元素合格，return true
        if(*(word+1)=='\0') return true;
        /*一般情况*/
        //如果未检查完，未超范围，元素==word[elemIdx]，安排下一步探查工作    
        char backup = board[row][col];//保存当前元素，之后用于恢复，避免影响之后的判断
        board[row][col]='\0';//标记本路线合格的元素，防止重复查找
        //四周有合格的就return true，不需要等最后在返回，最后返回false即可
        if(isExist(board,word+1,row-1,col)||isExist(board,word+1,row+1,col)||isExist(board,word+1,row,col-1)||isExist(board,word+1,row,col+1))
            return true;
        board[row][col] = backup;//恢复元素，避免给其他正确路线造成错误，如果不恢复，可能本路线是错误的，其他路线之后用该元素却是*了
        return false;//无通路，return false        
    }  
};
