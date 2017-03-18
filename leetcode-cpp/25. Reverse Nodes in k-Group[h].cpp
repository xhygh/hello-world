/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

tags:linked list;24m
*/

/**************************
解题思路：
【递归法】
将linkedlist分成k长度的小段，每个小段里面做k长度的linked list翻转，连接每个小段即可.

81 / 81 test cases passed.
Status: Accepted
Runtime: 23 ms
48.43%
时间复杂度O(n),空间复杂度O(1)
***************************/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //连基本的k=2都无法坐到或者不需要翻转
        if(head==NULL||head->next==NULL||k<2) return head;
        //分段
        ListNode* next_list = head; //下一小段的head
        for(int i=0;i<k;++i){
            if(next_list) next_list = next_list->next; //如果有后续node，null也行，就后移
            else return head;  //不够一个k长度的小段，直接返回这一小段不需要翻转
        }
        //开始反转，连接
        ListNode* reverse_next_list = reverseKGroup(next_list, k); //以翻转的下一小段
        ListNode* rear=NULL, *tmp = head, *tmpnext=NULL;
        while(tmp!=next_list){//没有反转完这一小段之前
            tmpnext = tmp->next; //保留下一个元素迭代器
            tmp->next = rear?rear:reverse_next_list;  //如果有本段中的反转段则连接，否则连接已反转的下一小段
            rear = tmp; //更新指向本段已经反转过的小段的head
            tmp = tmpnext;  //更新指向本段未反转过的小段的head
        }
        //本小段反转完成后返回本段的head
        return rear;
    }
};

/***************************
收获：考虑复杂问题的时候，可以想象如何把问题“分步化”，每一步完成一个任务，最后完成整个题目

解题思路：
和24M中K=2类似的想法，通过前面完成段的末节点，本小段的头结点，本小段的末节点，循环分段，反转，连接
在每个分段中执行反转连接函数，如果小段长度不够那么不进行反转，直接返回得到的结果。

81 / 81 test cases passed.
Status: Accepted
Runtime: 39 ms
4.17%
****************************/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*************
        本算法直接在原linked list上进行每小段的反转和连接，
        所以，当下一小段没有，或者当前小段不够k长度，直接
        返回结果即可.
        *************/
        //连基本的k=2都无法坐到或者不需要翻转
        if(head==NULL||head->next==NULL||k<2) return head;
        ListNode first(-1);
        first.next = head;
        
        ListNode *prev_end = &first, *end = head;//完成部分的末节点;开始是本小段的头结点，循环后是本小段的末节点
        while(end){
            //分段
            for(int i=1;i<k && end;++i)  end = end->next;  //找到本小段的end node
            if(end == NULL) break;  //如果本小段开头是null，或者本小段不够k长度，跳出循环返回结果
            //反转连接,返回完成部分的末节点prev_end
            prev_end = reverse_little_list(prev_end, prev_end->next, end);
            end = prev_end->next;//更新为下一小段的head
        }
        return first.next;
        
    }
private:
    //反转连接函数
    ListNode* reverse_little_list(ListNode* prev_end, ListNode* head, ListNode* end){
        /*
        输入完成部分的末节点，本小段的头结点，本小段的末节点
        返回连接后的末节点
        */
        //反转
        ListNode *reverse_head=NULL, *head_next=NULL;
        ListNode *next_head = end->next, *head_tmp = head;
        while(head_tmp!=next_head){//没有遍历完本小段指向下一小段开头时
            head_next = head_tmp->next;  //保存下一个要处理的本小段元素
            head_tmp->next = reverse_head; //依次用正序元素连接反转后的reverse_head
            reverse_head = head_tmp;  //更新反转后的head
            head_tmp = head_next;  //更新正序的head
            //因为有first node所以不用单独考虑第一小段
        }
        //连接
        prev_end->next = reverse_head;//完成部分的末节点与反转后head node连接
        head->next = next_head; //反转后的末节点与下一小段的头结点连接
        return head;  //此时head是反转后的末节点，end变为反转后的头结点
    }
    
};



/****************************
解题思路：
【我的迭代法】
从前到后，将list依次分为k长度的小段，每次反转每小段并与已经完成的部分连接。

81 / 81 test cases passed.
Status: Accepted
Runtime: 26 ms
27.25%
时间复杂度O(n),空间复杂度O(1)
****************************/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //连基本的k=2都无法坐到或者不需要翻转
        if(head==NULL||head->next==NULL||k<2) return head;
        
        //分段+反转每小段
        ListNode* next_list = head; //下一小段的head
        ListNode* back = NULL;  //已完成的小段的最后有元素的节点
        ListNode* list_head = NULL;  //保存当前小段的头结点
        while(next_list!=NULL){
            list_head = next_list;
        //分段，找到当前的这一小段的下一小段的list_head
            for(int i=0;i<k;++i){
                if(next_list) next_list = next_list->next; //如果有后续node，null也行，就后移
                else {//如果当前小段不够长，不需要反转
                    if(list_head == head)  return head; //如果第一小段就不用反转那直接返回
                    
                    back->next = list_head;//前面完成的小段与不反转的小段联合在一起并return
                    return head;//返回完成的list
                }  
            }
        //本小段可以开始反转
            ListNode* rear=NULL, *tmp = list_head, *tmpnext=NULL;//反转后的第一节点，反转前的本小段第一节点，本小段下一个要反转的节点
            ListNode* list_back = NULL;  //记录本小段的反转后的最后节点
            bool first = true;
            while(tmp!=next_list){//没有反转完这一小段之前
                tmpnext = tmp->next; //保留下一个元素迭代器
                tmp->next = rear;  //如果有本段中的反转段则连接，否则连接已反转的下一小段
                rear = tmp; //更新指向本段已经反转过的小段的head
                if(first) {//如果是第一个被反转的节点则是反转后的最后节点
                    list_back = rear;
                    first = false;
                }
                tmp = tmpnext;  //更新指向本段未反转过的小段的head
            }
            //处理第一小段的情况
            if(list_head == head) {
                head = rear;  //如果是第一个小段，那么更新头结点位置
                back = list_back;  //更新完成list的最后节点,此时不需要连接
                continue;  //开始第二小段
            }
        //连接前面完成段和本小段反转后的结果
            back->next = rear;  //连接
            back = list_back;  //更新完成list的最后节点
        }
        return head;
        
        
    }
};
