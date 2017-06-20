/*
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。 

*/

/*********
solution：

        //从前到后移动需要多次遍历，后边的字符，所以可以从后到前遍历。
        //首先遍历一个字符串，算出总长度n和空格个数m，
        //新字符串长度=n+2m
        //本问题注意字符串结尾的'\0'和空格变%20长度增长引起的内存问题，
        //需要询问面试官是在原地还是可以新建字符串处理，内存如何
 O(n),O(1)
运行时间：1ms

占用内存：500k


*********/

class Solution {
public:
	void replaceSpace(char *str,int length) {
        /*length是str的总容量*/
		//从前到后移动需要多次遍历，后边的字符，所以可以从后到前遍历。
        //首先遍历一个字符串，算出总长度n和空格个数m，
        //新字符串长度=n+2m
        //本问题注意字符串结尾的'\0'和空格变%20长度增长引起的内存问题，
        //需要询问面试官是在原地还是可以新建字符串处理，内存如何
        if (str==nullptr||length<=0) return;  //空指针，或者空串
        int n=0,m=0;

        for(int i=0;str[i]!='\0';++i){
            ++n;
            if (str[i]==' ')
                ++m;
        }
        int newn = n+2*m;
        if (newn>length)	
            return;//越界返回
        int p2 = newn;
        int p1 = n;
        while(p1>=0&&p2>p1){
            //p2追上p1那么前面的就不用挪了
            if(str[p1]==' '){
				str[p2--]='0';
                str[p2--]='2';
                str[p2--]='%';
            }
            else
                str[p2--] = str[p1];
            --p1;
        }
        
	}
};
