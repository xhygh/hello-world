/*
输入数字n，按顺序打印从1到最大

*/

/********
主要陷阱在考虑大数溢出问题（用字符串或者数组保存数据），
加一问题，加一时如何知道到达了最大的数字(最高为，即idx=0处的数据发生进位);
打印陷阱从第一个不是0的数字开始打印(标志为判断下)


看起来简单，但是到处都是陷阱，需要谨慎思考
*******/
class Solution17{
public:
    void printToMaxOfNDigits(int n){
        if(n<=0)
            return;
        char* num=new char[n+1];//建立数组，表示超大数字
        memset(num,'0',n);
        num[n]='\0';//数字字符串尾巴
        while(!incream(num)){
            printnum(num);
        }
        delete[] num;
    }
    bool incream(char* num){
        //加一函数
        bool isOverflow=false;//是否到达最大数字
        int carry = 0;//进位记录
        int len = strlen(num);
        for(int i=len-1;i>=0;--i){
            int sum = num[i]-'0'+carry;//计算本位加和结果
            carry = 0;//其实每必要，
            if(i==len-1)
                sum++;//如果是最低位，记得+1
            if(sum>=10){
                //逢十进一
                if(i==0)
                    isOverflow=true;
                else{
                    carry = 1;//进位记录,因为只能进1,且只加一，所以不用清零，到第二个不用进位的数位就直接退出了
                    num[i]='0'+sum-10;
                }

            }
            else{
                //如果没有造成进位
                num[i] = '0'+sum;
                break;
            }
        }
        return isOverflow;
    }
    void printnum(const char* num){
        //从第一个不是0的数字开始打印
        bool isbegin0=true;
        int len = strlen(num);
        for(int i=0;i<len;++i){
            if(isbegin0 && num[i]!='0')
                isbegin0=false;
            if(!isbegin0)
                cout<<num[i];
        }
        cout<<endl;
    }

};


/****
其实就是10个数字全排列，全排列用递归可以解决
与上一个方法不同之处是，加一被全排列递归取代。

*****/

class Solution17{
public:
    void printToMaxOfNDigits(int n){
        if(n<=0)
            return;
        char* num=new char[n+1];//建立数组，表示超大数字
        memset(num,'0',n);
        num[n]='\0';//数字字符串尾巴
        for(int i=0;i<10;i++){
            num[0] = '0'+i;//全排列最高为
            printMax(num,n,0);
        }
        delete[] num;
    }
    void printMax(char* num, int n,int idx){
        if(idx==n-1){
            //如果上一个数位处理的是个位，打印结果
            printnum(num);
            return;
        }
        for(int i=0;i<10;i++){
            //如果上一个数位不是个位，处理下一个数位
            num[idx+1]='0'+i;
            printMax(num,n,idx+1);
        }
    }
    void printnum(const char* num){
        //从第一个不是0的数字开始打印
        bool isbegin0=true;
        int len = strlen(num);
        for(int i=0;i<len;++i){
            if(isbegin0 && num[i]!='0')
                isbegin0=false;
            if(!isbegin0)
                cout<<num[i];
        }
        cout<<endl;
    }

};
