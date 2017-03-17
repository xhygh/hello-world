/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed. 

tags:linked list;25h
*/

/*******************

解题思路：(觉得自己这个挺好)
做了几道linked list的题之后发现，想问题的时候，要假设前面的已经完成，现在处理的剩下的一些。

假设之前已经完成了一部分，那么就会有头结点和目前的末节点，设该节点为tmp，
如此tmp.next = head,由于之后的部分是我们需要返回的，所以可以用目前的末节点作为我们的首节点，引导后面的部分。
则有head = &tmp,设p指向每相邻对的第一个节点，如果假设前面都完成了，那么这里有3种情况，1.p=null，直接return head->next；
2.p!=null && p->next==null，return head;3.至少还有2个节点.
对于3.处理如下：
//将p与p->next换位置，基本链表操作
tmp->next = p->next;
p->next = p->next->next;
temp->next->next = p;
//恢复到之前我们假设时的状态
tmp = p;
p = p->next;//此时链表的状态和我们一开始假设的状态相同，只需要循环以上处理方案，每次由1.2.判断p的情况即可。
最后返回head->next.

55 / 55 test cases passed.
Status: Accepted
Runtime: 3 ms
34.52%
时间复杂度O(n)，空间复杂度O(1)
**********************/

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode* p = head;
        ListNode tmp(0);
        tmp.next = head;
        head = &tmp;
        while(p!=NULL && p->next!=NULL){
            head->next = p->next;
            p->next = p->next->next;
            head->next->next = p;
            head = p;
            p = p->next;
        }
        return tmp.next;
    }
};
