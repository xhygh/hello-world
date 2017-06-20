/*
题目2：
在一个长度为n+1的数组里的所有数字都在1～n的范围内，所以数组中至少有一个数字是重复的，
请找出数组中任意一个重复的数字，但不能修改输入的数组。例如，如果输入长度为8的数组{2,3,5,4,3,2,6,7},
那么对应的输出是重复数字2或者3

    int a1[]={2,3,5,4,3,2,6,7};
    int a2[]={1,3,0,2};
    int a3[]={6,2,0,1};
    int a4[0];
    offer0301041 s;
    int* d=new int;
    int b1 = s.getDuplicateNum(a1,8);  //3
    int b2 = s.getDuplicateNum(a2,4);  //-1
    int b3 = s.getDuplicateNum(a3,4);//-1
    int b4 = s.getDuplicateNum(a4,0);//-1
    int b5 = s.getDuplicateNum(nullptr,4);//-1
*/

/************
solution：
//O(nlgn),O(1)时间换空间，二分法，将1～n个数值分为两部分，遍历数组分别统计1～n/2 和 n/2+1~n之间的数值数量。
//如果哪个部分的元素个数超过了数值个数，那么这一部分有重复数字，，例如是1～n/2，那么在将这部分数值二分，重复之前的统计操作。
***********/

class offer0301041{
public:
    int getDuplicateNum_array(const int* numbers,int length){
        //O(n),O(n)额外建立辅助数组，空间换时间
        if(numbers== nullptr||length<=0) return -1;//如果是空指针或者长度不够
        int nums[length] = {0};
        for(int i=0;i<length;i++){
            nums[i] = numbers[i];
        }
        //如果数组包含有效输入，但可能有超纲数字
        for(int i=0;i<length;++i){
            while(nums[i]!=i){
                if (nums[i]<0||nums[i]>length-1) return -1;//元素值超过范围
                if(nums[i]==nums[nums[i]]) //如果当前元素的值等于该元素值为索引的位置的元素值，即有两个元素相等，则有重复
                    //有重复
                    return numbers[i];//保存重复元素值

                else{//如果不相等，通过交换将元素换到其元素值作为索引的位置上
                    //交换两个元素
                    int tmp = nums[i];
                    nums[i] = nums[nums[i]];
                    nums[tmp] = tmp;//这里需要注意都是tmp
                }
            }
        }
        return -1;//遍历数组都没有重复数字
    }

    int getDuplicateNum(const int* numbers,int length){
        //O(nlgn),O(1)时间换空间，二分法，将1～n个数值分为两部分，遍历数组分别统计1～n/2 和 n/2+1~n之间的数值数量。
        //如果哪个部分的元素个数超过了数值个数，那么这一部分有重复数字，，例如是1～n/2，那么在将这部分数值二分，重复之前的统计操作。
        if(numbers== nullptr||length<=0) return -1;//如果是空指针或者长度不够
        int start = 1;//数值开始区间
        int end = length-1;//数值区间结束值
        //区间分割[start,end],[end+1,length-1]
        while(end>=start){  //运行O(nlgn)次
            int mid = ((end-start)>>1) + start; //3>>1=1 8|4,9|5
            int cnt = cntRange(numbers,length,start,mid); //统计[start,mid]内元素个数
            if(end==start){
                //如果区间内只有一个元素
                if(cnt>1) return start;//这个元素就是重复的
                else
                    break;//不是重复的，此时就是
            }
            if (cnt>(mid-start+1))
                end = mid;//如果元素个数大于数值个数，那么该区间内有重复元素，更新end
            else
                start = mid+1;//如果另一区间内有重复元素，更新start
        }
        return -1;//都找完了，没有重复的,如果输入length==1，肯定没重复的

    }
    int cntRange(const int* numbers,int length,int start,int end){
        if(numbers== nullptr) return 0;//如果是空指针
        int cnt=0;
        for(int i=0;i<length;i++)
            if(numbers[i]>=start && numbers[i]<=end)
                ++cnt;  //O(n)
        return cnt;
    }

    int getDuplicateNum_hash(const int* numbers,int length){
        //使用哈希表记录已经出现过的元素，每次判断元素是否超出范围，是否在哈希表中，
        //合法的元素值加入哈希表
        //O(n),O(n)
        if(numbers== nullptr||length<=0) return -1;//如果是空指针或者长度不够
        unordered_set<int> elems; //unordered_set对应的数据结构是哈希表，查找效率高，但额外空间复杂度高
        for(int i=0;i<length;++i){
            if(numbers[i]<0||numbers[i]>=length) return -1;
            if(elems.find(numbers[i])!=elems.end()){
                //如果该元素出现过
                return numbers[i];
            }
            else
                elems.insert(numbers[i]);
        }
        return -1;
    }
};
