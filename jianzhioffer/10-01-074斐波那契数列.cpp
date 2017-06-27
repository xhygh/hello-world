/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
斐波那契数列定义：
      0, n=0
f(x)= 1, n=1
      f(n-1)+f(n-2), n>1
*/

/************
采用公式迭代法，当前项等于前两项的加和。

运行时间：2ms
占用内存：496k
O(n),O(1)
**********/
class Solution {
public:
    /*
    递归算法太慢，慢的难以忍受，大量的重复计算
    */
    int Fibonacci(int n) {
		/**
        * 从下网上计算，前面计算出的数据保留作为后面计算用的，如此时间复杂度O(n)
        * 
        */
        if(0<=n&&n<2) return n;
        int f1=0, f2=1,result=0;
        for(int i=2;i<=n;++i){
            result=f1+f2;
            f1 = f2;
            f2 = result;
        }
        return result;
    }
};
