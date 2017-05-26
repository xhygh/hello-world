/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 


tags:linked list;two pointers
*/
/*
将链表的右边数第n个节点移除
solution：
链表删除，快慢指针
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n<=0) return head;
        ListNode *faster=head,*smaller=head;
        while(n-->0) faster=faster->next;
        if(faster==nullptr) return head->next;//只有一个元素，且要删除它
        while(faster->next!=nullptr){//开始找要删除当元素的位置，smaller的在目标元素之前一个
            smaller=smaller->next;
            faster=faster->next;
        }//faster到达最后一个元素
        smaller->next = smaller->next->next;//删除目标元素
        return head;
        
    }
};
