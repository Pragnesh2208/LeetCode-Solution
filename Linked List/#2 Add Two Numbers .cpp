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
/********************Optimal approach to Add two numbers in Linked List*********************/
/*******************Time complexity = O(max(M,N))*******************************************************/
/*******************Space complexity = O(max(M,N))*****************************************************/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr1 = l1 , *ptr2 = l2;
        ListNode * dummy = new ListNode(0);
        ListNode * ptr3 = dummy;
        int carry = 0;
        while(ptr1 != NULL || ptr2 != NULL || carry != 0 ) {
            int sum = 0;
         if( ptr1 != NULL) {
                sum +=ptr1 -> val;
                ptr1  = ptr1 -> next ;
            }
        if( ptr2 != NULL) {
                sum +=ptr2 -> val;
                ptr2  = ptr2 -> next ;
            }
         sum += carry;
            carry = sum / 10;
            ListNode * temp  = new ListNode (sum % 10);
            ptr3 -> next = temp;
            ptr3 = ptr3 -> next;
        }
        return dummy -> next;
       
        
    }
};