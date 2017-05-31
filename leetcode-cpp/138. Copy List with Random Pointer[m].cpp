/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 

tags:hash table,linked list;133m
*/


/************
一个链表，每个node上都有一个随机指针，指向null或者链表中的元素，返回一个该链表的深度拷贝
solution:
第一遍，将顺序链表拷贝下来，同时建立一个map，原node:新node,如此找到原node的random pointer能通过map找到新node的random pointer。
可以称之为平行拷贝方法，该题难点在于如何使新旧node对应起来，对应起来找到旧node的random才能找到新node的random
12 / 12 test cases passed.
	Status: Accepted
Runtime: 69 ms
16.08%
O(n),O(n)
***********/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode tmp(-1);
        RandomListNode* curo = head;
        RandomListNode* curn = &tmp;
        unordered_map<RandomListNode*,RandomListNode*> oldnew;
        while(curo!=nullptr){
            RandomListNode* newnode = new RandomListNode(curo->label); //注意这里，必须如此
            oldnew[curo]=newnode;
            curn->next = newnode;
            curn = curn->next;
            curo = curo->next;
        }
        curo = head;
        curn = tmp.next;
        while(curo!=nullptr){
            if (curo->random==nullptr)
                curn->random=nullptr;
            else
                curn->random = oldnew[curo->random];
            curn = curn->next;
            curo = curo->next;
        }
        return tmp.next;
    }
};
