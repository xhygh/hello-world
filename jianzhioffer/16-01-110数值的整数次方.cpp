/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
不得使用库函数，不用考虑大数问题
*/


/******

运行时间：3ms
占用内存：500k
*****/

class Solution {
public:
    double Power(double base, int exponent) {
        bool g_InvalidInput=false;//全局变量记录错误
    	if(equal(base,0.0)){//考虑base为0的情况
            if(exponent<0)
            	g_InvalidInput=true;//指数<0那么错误记录
            else 
              	return 0.0;//统一返回0
        }
        unsigned int absE = exponent>=0?(unsigned int)exponent:(unsigned int)(-exponent);//指数先绝对化
        double result = powit(base,absE);
        if(exponent<0)
            result=1.0/result;//负数指数求倒数
        return result;
    }
    double powit(double base,unsigned int exponent){
        double result=1.0;
        for(int i=0;i<exponent;++i){//计算指数运算
            result*=base;
		}
        return result;
    }
    bool equal(double a,double b){//测试两个double是否相等
        if(fabs(a-b)<0.000001)
            return true;
        return false;
    }
};
