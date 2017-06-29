/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        /*
		*使用二分查找[]形式。
		*修改部分是，根据题目定义，总数组由两个分数组构成，前一段是升序，后一段也是升序
		*start<=mid（属于前半段的最后一个数据）,mid+1<=end
		**/
		if (rotateArray.size()<1)
			throw "input err!";
        
		int left = 0;
		int right = rotateArray.size() - 1; //[left,right]
	
		while (left <= right){
            if(right-left==1)
                return rotateArray[right];//仅有2个元素时候
            
			int mid = left + ((right - left) >> 1);
            
            if(rotateArray[left]==rotateArray[mid]&&rotateArray[left]==rotateArray[right])
                //如果三者都相等，无法判断前后段特征，之后顺序查找结果并返回
                return Minelem(rotateArray,left,right);
            
			if (rotateArray[left] < rotateArray[right])
				return rotateArray[left];//如果left<right证明都是升序，直接返回left
            
			if (rotateArray[left] <= rotateArray[mid]){
				//前边是升序
				left = mid;//加不加1都行
			}
			else if (rotateArray[mid] <= rotateArray[right]){
				//后面是有序的
				right = mid;
			}
		}
	}
    
    int Minelem(vector<int>nums,int left,int right){
        int result=nums[left];
        for(int i=left+1;i<=right;++i){
            if(result> nums[i])
                result=nums[i];
        }
        return result;
    }
    
};
