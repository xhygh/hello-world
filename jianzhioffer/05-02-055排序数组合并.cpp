/*
两个有序数组A1和A2,内存在A1末尾有足够多的空余空间容纳A2,请将A2插入A1中，且保持有序。

*/

/*******
solution
从后向前查，假设原始顺序是升序，那么从后向前降序归并连个数组
O(n),O(1)
******/

class offer0502055{
public:
    void merge(int a1[],int a2[],int n1,int n2){
        if(a1==nullptr||a2==nullptr||n1<=0) return;

        for(int i=n1-1,j=n2-1,k=n1+n2-1;k>=0;){
            if(j<0||(i>=0&&a1[i]>=a2[j])){  //注意另一个数组已经完成的情况在先，本数组未完在后，然后是大小关系，先考虑边界情况
//                cout<<a1[i]<<endl;
                a1[k] = a1[i];
                --i;

            }
            else if(i<0||(j>=0&&a1[i]<a2[j])){
//                cout<<a2[j]<<endl;
                a1[k] = a2[j];
                --j;
            }
            --k;
        }
    }
};
