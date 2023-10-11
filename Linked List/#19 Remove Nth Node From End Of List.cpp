/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/********************Optimal approach to Remove Nth Node From End Of Linked Lists*****************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    ListNode  * traverse (ListNode  * head , int n) {
        while(head != NULL && n) {
            head = head -> next;
            n--;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * ptr1 = head , *ptr2 = head;
        ptr2 = traverse( head , n);
        
        while(ptr2 != NULL && ptr2 -> next != NULL)  {
            ptr2 = ptr2 -> next;
            ptr1 = ptr1 -> next;
        }
        
        if(ptr2 != NULL) {
        ptr1 -> next = ptr1 -> next -> next ;
        } 
        
        else {
            head = head -> next;
        }
        
        return head;
    }
};


/********************Optimal approach to Remove Nth Node From End Of Linked Lists*****************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummyHead = new ListNode(0);
        ListNode * fPtr = dummyHead , *sPtr = dummyHead;
        ListNode * tail = dummyHead;
        dummyHead -> next = head;

        while(n--) {
            fPtr = fPtr -> next;
        }

        while(fPtr -> next != NULL) {
            fPtr = fPtr -> next;
            sPtr = sPtr -> next;
        } 

        sPtr -> next = sPtr -> next -> next;

        return dummyHead -> next;
    }
};