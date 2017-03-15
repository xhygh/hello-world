/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
【tags】Linked List
【similar problems】23h,88e,148m
*/

/*****************************

解题思路：

算法课上有讲到类似的题目，不过这道题目是在原本的两个list上修改，不允许重新建立list，所以用指针。
【在现有的两个list上产生新的list】
res为新list的首节点，无val，新list的尾节点为rear。
假设l1->val <= l2->val如此，res.next = l1（主体函数单写一个，调用之前比较两个头节点就可以）。
rear = l1,如此新list是寄生在l1上的，
l1 = l1->next，l1的新头节点为原来的第二节点（如果有），
这样，只要一直判断l1,l2存在否，对比l1和l2的头节点大小，
较小的接入res的尾部，然后更新该list的首节点即可。

因为两个list都是sort的，所以里面不排除有重复的数字，
更新l1和l2的头节点时，可以一直找到相同数字的最后一个作为rear，
然后再后移一个节点即可。

当其中一个list结束的时候，直接令rear->next=存活头节点即可。

208 / 208 test cases passed.
Status: Accepted
Runtime: 9 ms

时间复杂度O(n),空间复杂度O(1)
******************************/


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 && l2)
            return (l1->val)<=(l2->val)?mergeSortTwoLists(l1, l2):mergeSortTwoLists(l2, l1);
        else if(l1 && !l2) return l1;
        else return l2;
        
    }
private:
    ListNode* mergeSortTwoLists(ListNode* l1, ListNode* l2) {
        ListNode res(-1);  //front of new list
        ListNode* rear;  //rear of new list 
        

        res.next = l1;
        rear = l1; //rear of new list 
        if (l1->next)
            l1 = l1->next; //l1头
        else{  //如果l1阵亡，那接上l2返回res
           rear->next = l2; 
           return res.next;
        }
        
        while(l1 || l2){
            if(l1->val<=l2->val){
                rear->next = l1;
                while(l1&&l1->next&&l1->val==(l1->next)->val) l1 = l1->next;//没有后节点或者不等于则继续
                rear = l1; //rear of new list 
                if (l1->next&&l1->val!=(l1->next)->val) //如果有后节点，但是不等于
                    l1 = l1->next; //l1头
                else{  //如果l1没有后节点，那接上l2返回res
                    rear->next = l2; 
                    return res.next;
                }
            }
            else{
                rear->next = l2;
                while(l2&&l2->next&&l2->val==(l2->next)->val) l2 = l2->next;
                rear = l2; //rear of new list 
                if (l2->next&&l2->val!=(l2->next)->val)
                    l2 = l2->next; //l2头
                else{  //如果l1阵亡，那接上l1返回res
                    rear->next = l1; 
                    return res.next;
                }
            }
        }
    
    }
};



/*******************************

方法2
归并算法
208 / 208 test cases passed.
Status: Accepted
Runtime: 15 ms
时间复杂度O(n),空间复杂度O(1)
********************************/


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode res(0);
        ListNode *rear = &res;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                rear->next = l1;
                l1 = l1->next;
            } else {
                rear->next = l2;
                l2 = l2->next;
            }
            rear = rear->next;
        }
        if (l1) rear->next = l1;
        else rear->next = l2;
        return res.next;
    }
};
