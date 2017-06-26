/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

*/

/**********
栈的特点是先进后出，队列的特点是先进先出。
运行时间：1ms
占用内存：500k

********/

class Solution
{
public:
    /*
    *考虑栈和队列的特点，如果s1中有元素，s2为空，先要pop，元素需要翻个，即扔到s2中，此时pop s2可以
    *如果想要e入队，从后入，所有直接打入s1即可，e之前的元素都在s2中，e之后的在s1中，不冲突，如果想要pop
    *e及其之后的元素，需要先把e之前的元素pop干净，即将s2清空，不冲突。
    */
    void push(int node) {
        //直接往S1中装入即可
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){//如果s2为空，把s1的扔到s2
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty())
            throw "queue is empty!";//注意这里
        int tmp = stack2.top();
        stack2.pop();//只要s2有元素，直接pop
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
