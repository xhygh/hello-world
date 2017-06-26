/**

使用两个队列实现栈的push和pop
*/

/***********
栈，push，从尾部压入元素；pop从尾部删除元素。
队列，push，从尾部压入元素，pop从头部删除元素。
所以，用队列模拟栈，push好说，重要是pop。pop需要把队列中目标元素e之前的元素全部弹出到另一个队列，然后删除e。
然后吧剩余的元素压入另一个队列，在重新装回本队列，防止下次删除那个队列的元素，倒不开。
*********/

class Cstack{
public:
    void push(int node){
        q1.push(node);
    }
    
    int pop(){
        if(q1.size()<=0){
            if(q2.size()<=0)
                throw "stack is empty";
            while(q2.size()>0){
                q1.push(q2.top());
                q2.pop();
            }
        }
        if(q1.size()>1){
            q2.push(q1.top());
            q1.pop();
        }
        int tmp = q1.top();
        q1.pop();
        return tmp;
    }
private:
    queue<int> q1;
    queue<int> q2;
};
