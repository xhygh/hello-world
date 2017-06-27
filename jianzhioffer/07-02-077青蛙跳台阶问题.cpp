/*
一只青蛙一次可以跳上一级台阶，也可以一次跳2级台阶，求该青蛙跳到n级台阶总共有多少种跳法。
*/


/************
斐波那契数列

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
        if(1<=n&&n<3) return n;
        int f1=1, f2=2,result=0;
        for(int i=3;i<=n;++i){
            result=f1+f2;
            f1 = f2;
            f2 = result;
        }
        return result;
    }
};
