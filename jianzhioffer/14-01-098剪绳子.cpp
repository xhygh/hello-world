/*
一条长度n的绳子，请把绳子剪成m段，n>1,m>1且都是整数，每段绳子长记为k[0].k[1],k[2],...,k[m]。
求这些小段绳子的长度乘积最大是多少？例如，n=5时，分为2和3的两段，长度为6.
*/

/*********
第二版新家的题目
用动态规划，
从上往下思考，n长的绳子可以分成1和n-1等等的两端，然后长的还可以再分成短的。
所以最优子结构是f(n)=maxf(i)*f(n-i),0<i<n
如果从上往下使用递归方法，会重复计算很多东西，
所以采用从下到上计算方法，需要求的是长度为length的乘积，但是从i=2开始计算，
i<4的长度可以直接返回，i>=4时，因为长度为2或3的子段不切是最长的，所以需要手动设置。
然后就从i=4开始，根据之前0,1,2,3记录的0,1,2,3乘积长度，计算更长的最优解。
更长的最优解用到了前面的结果，直接从数组提取即可，不需要再次计算，节省了时间。
O(n^2)   O(n)
********/


class Solution13 {
public:
	int maxProductAfterCutting(int length){
		//f(n)=max(f(i)*f(n-i)) 0<i<n
		if (length < 2)
			return 0;
		if (length == 2)
			return 1;
		if (length == 3)
			return 2;
		int* prod = new int[length + 1];//i>3,表示长度为i的绳子切分的最大乘积
		prod[0] = 0;
		prod[1] = 1;
		prod[2] = 2;
		prod[3] = 3;
		int max = 0;
		for (int i = 4; i <= length; i++){//i表示绳子长度
			max = 0;
			for (int j = 1; j <= i / 2; ++j){
				int product = prod[j] * prod[i - j];
				if (max < product)
					max = product;
			}
			prod[i] = max;
		}
		max = prod[length];
		delete[] prod;
		return max;
	}

	int maxProdAfterCutting(int length){
		//贪心算法
		//尽可能多的剪出3的长度的绳子，如果余1，那就并成4，将4分为2+2
    //数学证明这个是对的
		if (length < 2)
			return 0;
		if (length == 2)
			return 1;
		if (length == 3)
			return 2;
		int time3 = length / 3;
		if (length % 3 == 1)
			time3 -= 1;//合并为4
		int time2 = (length - time3 * 3) / 2;

		return pow(3, time3)*pow(2, time2);
	}
};
