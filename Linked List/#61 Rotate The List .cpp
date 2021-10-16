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
/********************Optimal approach to Rotate the  Linked Lists *********************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
   
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode  * ptr1 = head ;
        if(head != NULL ) {
       // we will calculate the size of Linked List and make it circular 
     int size = 1;
        while(ptr1 -> next != NULL) {
             ptr1 = ptr1 -> next;
            size++;
        }
        ptr1 -> next = head;
            
 // if k!= 0  then we will travers else we dont;
        if (k %= size)
        for( auto i = 0 ; i< size - k ;i++) {
            ptr1 = ptr1 -> next;
        }
    
            head = ptr1 -> next;
         ptr1 -> next =NULL;
        }
        return head;
        
    }
};