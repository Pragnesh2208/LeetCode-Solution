/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/********************Optimal approach to Check if cycle present in Linked List or Not*********************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * ptr1 = head ,*ptr2 = head;
        
        while( ptr2 != NULL && ptr2 ->next != NULL  && ptr2 -> next -> next !=NULL) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next->next;
            
            if(ptr1 == ptr2 )
                break;
        }
         ptr1 = head;
        while( ptr2 != NULL && ptr2 -> next != NULL && ptr2 -> next -> next != NULL &&  ptr1 != ptr2) {
            ptr2 = ptr2 -> next;
            ptr1 = ptr1 -> next;
           
        }
        
        return (ptr2 == NULL || ptr2 -> next  == NULL || ptr2 -> next -> next == NULL) ? NULL : ptr2;
    }
};