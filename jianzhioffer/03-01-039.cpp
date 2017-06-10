/*
找出数组中重复的数字
在一个长度为n的数组里的所有数字都在0到n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。

测试用例：
1.长度为n的数组里包含一个或多个重复的数字；
2.数组中不包含重复的数字；
3.无效输入（输入空指针；长度为n的数组中包含0～n-1之外的数字）

    int a1[]={2,3,1,0,2,2,1}; //=7
    int a2[]={1,3,0,2};  //n=4
    int a3[]={6,2,0,1};//n=4
    int a4[0];//n=0
    
int a1[]={2,3,1,0,2,2,1};
int a2[]={1,3,0,2};
int a3[]={6,2,0,1};
int a4[0];
offer0301039 s;
int* d=new int;
bool b1 = s.duplicateNum(a1,7,d); //true,2
bool b2 = s.duplicateNum(a2,4,d);  //false
bool b3 = s.duplicateNum(a3,4,d);  //false
bool b4 = s.duplicateNum(a4,0,d);  //false
bool b5 = s.duplicateNum(nullptr,4,d);  //false

*/

/***********
solution1
排序法，排序之后，遍历数组，找到第一个与前一个值相同的元素输出

**********/



/************
solution3:
对于数组中每个idx的元素，判断num[idx]？=idx如果不相等，则判断num[idx]与num[num[idx]],相等则是重复数字，直接返回，否则交换位置。

***********/
class offer0301039{
public:
    bool duplicateNum(int nums[],int n,int *duplication){
        if(nums== nullptr||n<=0) return false;//如果是空指针或者长度不够

        //如果数组包含有效输入，但可能有超纲数字
        for(int i=0;i<n;++i){
            while(nums[i]!=i){
                if (nums[i]<0||nums[i]>n-1) return false;
                if(nums[i]==nums[nums[i]]){
                    //有重复
                    *duplication=nums[i];
                    return true;
                }
                else{
                    //交换两个元素
                    int tmp = nums[i];
                    nums[i] = nums[nums[i]];
                    nums[tmp] = tmp;
                }
            }
        }
        return false;//遍历数组都没有重复数字
    }
};
