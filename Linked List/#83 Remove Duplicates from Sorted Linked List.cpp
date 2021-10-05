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
/********************Optimal approach to Remove Duplicates from Linked List*********************/
/*******************Time complexity = O(N) ***********************************************/
/*******************Space complexity = O(1)  *********************************************/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       
         ListNode *first = head;
         ListNode *second = head;
        while ( second!=NULL )
        {
            if ( second->val !=first->val ) {
                first->next = second;
                second = second->next;
                first = first->next;
            } else {   
                second = second->next;
            }
              
            first->next = NULL;
        }
        
        return head;
        
    }
};