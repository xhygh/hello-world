/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
【tags】Linked List，math
【similar problems】43m,67e,371e,415e,445m

*/

/**********************
29ms
(加法器)
（1）	顺序遍历链表，由于是低位在前，所以直接对应位加和并保留进位；
（2）	2个对应位和1个进位只要有一个非0就继续加node，提前结束的链表对应位为0；
（3）	2个对应位和1个进位都是0的时候停止并返回链表结果。

***********************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(-1);  //结果保存
        int c = 0;
        ListNode *ptmp = &result;
        for(ListNode *p1=l1,*p2=l2;p1!=nullptr || p2!=nullptr|| c!=0;
            p1 = p1==nullptr?nullptr:p1->next,p2 = p2==nullptr?nullptr:p2->next,
            ptmp = ptmp->next){
            int a = p1==nullptr?0:p1->val;
            int b = p2==nullptr?0:p2->val;
            int sum = a+b+c;
            c = sum/10;
            ptmp->next = new ListNode(sum%10);
        }
        return result.next;
    }
};
