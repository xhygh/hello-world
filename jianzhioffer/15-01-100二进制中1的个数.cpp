/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

*/

/******
设输入数据为num
思路1：
令num&1，如果结果为1，cnt+1;
num>>1，重复上一步，直到n为0;
问题1：如果输入的是负数，右移的时候高位补1，这样会陷入死循环。
解决办法&思路2：左移1，num不动，直到左移至0
运行时间：1ms

占用内存：492k

*****/
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt=0;
         unsigned int flag=1;
         while(flag){
             if(n&flag)
                 cnt++;
             flag<<=1;
         }
         return cnt;
     }
};


/*****
思路3：
         //(n-1)&n 结果会把n当二进制形式中最右边的1变0
         //1100-1=1011,1100&1011=1000
         //所以减几次到0就有几个1
运行时间：1ms

占用内存：500k


****/

class Solution {
public:
     int  NumberOf1(int n) {
         //(n-1)&n 结果会把n当二进制形式中最右边的1变0
         //1100-1=1011,1100&1011=1000
         //所以减几次到0就有几个1
         int cnt=0;
         while(n){
             cnt++;
             n=(n-1)&n;
         }
         return cnt;
     }
};
