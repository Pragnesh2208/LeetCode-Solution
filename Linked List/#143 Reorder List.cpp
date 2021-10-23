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
/********************Optimal approach to Reorder Lists*****************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    ListNode *reverse(ListNode * head ) {
        
        ListNode * prev = NULL;
        
        while(head != NULL ) {
            
            ListNode * Next = head -> next;
            head -> next  = prev;
            prev = head; 
            head = Next;  
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode * ptr1 = head , *ptr2 = head;
        
        while(ptr2 -> next != NULL && ptr2 -> next -> next != NULL) {
            
            ptr2 = ptr2 -> next -> next;
            ptr1 = ptr1 -> next;
        }
        
        ptr2 = reverse(ptr1 -> next);
        ptr1 -> next = NULL;
        ptr1 = head;
        
        while(ptr2 != NULL) {
            
        ListNode  * Next1 = ptr1 -> next;
        ptr1 -> next = ptr2;
        ListNode * Next2 = ptr2 -> next;
        ptr2 -> next = Next1;
        ptr2 = Next2;
        ptr1 = Next1;
            
        }
    }
};