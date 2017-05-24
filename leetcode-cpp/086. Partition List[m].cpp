/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 

tags: linked list;two pointers;

*/

/*
给出一个单链表，一个值x，所有小于x的节点在大于等于x的节点前面，需要保留两个部分中节点当原相对顺序。
solution:
新建两个head，head1引领小于部分，head2引领大于部分。
遍历原链表，通过判断和x当大小关系，分入两个head，最后将head2连接入head1的尾部。
# 注意：链表问题，新建额外节点可节省很多功夫。

166 / 166 test cases passed.
	Status: Accepted
Runtime: 6 ms
27.66%
O(n),O(1)使用了额外空间2个
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
    ListNode* partition(ListNode* head, int x) {
        ListNode less(-1);
        ListNode greater(-1);
        
        ListNode* l = &less;
        ListNode* g = &greater;
        ListNode* cur = head;
        while(cur){
            if(cur->val<x){
                l->next = cur;
                l = cur;
            }
            else {
                g->next = cur;
                g = cur;
            }
            cur = cur->next;
        }
        l->next = greater.next;
        g->next = nullptr;
        return less.next;
    }
};

