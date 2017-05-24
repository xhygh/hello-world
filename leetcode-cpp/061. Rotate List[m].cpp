/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
tags:linked list;two pointers;189e
*/

/*
在右边数第k个元素处旋转list，右边的拿到左边。
solution:
首先，考虑head存在和k==0的问题;
然后，给出当右边第k个，需要知道左边第k‘个，需要遍历原list;
然后，len<k如何解决，可以问面试官是否可以循环读取，如果是，那就需要取余;
遍历当时候指针指到最后一个了，直接利用它令原list变环，然后循环k’次确定新的head，尾巴记得nullptr;
return newhead
230 / 230 test cases passed.
	Status: Accepted
Runtime: 19 ms
7.87%
o(n),O(1)
*/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr||k==0) return head;
        
        ListNode *p = head;
        
        int len = 1;
        while(p->next){
            len++;
            p = p->next;
        }
        
        k = len-k%len;
        p->next = head;//首尾相连
        for(int i=0;i<k;i++)
            p=p->next;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
