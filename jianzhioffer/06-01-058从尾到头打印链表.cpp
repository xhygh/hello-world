/*
输入一个链表，从尾到头打印链表每个节点的值。

*/

/******
注意询问，是否可以改变list结构，是否可以使用额外空间。
因为有“后进先出”的思想，用stack保存val，在输出.
运行时间：1ms

占用内存：496k
******/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if(head==nullptr) return vec;
        ListNode *p = head;
        stack<int> s;
        while(p!=NULL){
            s.push(p->val);
            p=p->next;  //别少了这个
        }
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
        return vec;
    }
};

/******
递归版
因为栈的本质就是递归，所以可是改写称递归模式
******/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        //递归方法,栈的本质就是递归
        vector<int> vec;
        printList(head,vec);
        return vec;
        
    }
    
    void printList(ListNode* head, vector<int>& vec){
        if(head!=nullptr){
            if(head->next!=nullptr)
                printList(head->next,vec);
            vec.push_back(head->val);
        }
    }
};
