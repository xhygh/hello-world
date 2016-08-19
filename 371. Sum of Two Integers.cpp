'''Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
'''

class Solution {
public:
    int getSum(int a, int b) {
        //while(b){
        //    int temp = a;
        //    a = temp^b;
        //   b = (temp&b)<<1;
        //}
        //return a;
        return b==0?a:getSum(a^b,(a&b)<<1);
    }
    
};
