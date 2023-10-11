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
/***********************Clean Code*******************************************************/
/********************Optimal approach to Remove Duplicates from Linked List*********************/
/*******************Time complexity = O(N) ***********************************************/
/*******************Space complexity = O(1)  *********************************************/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode * first = head  , * second = head -> next;
        while(second != NULL) {
            if(first -> val == second -> val) {
                ListNode * temp = second -> next;
                first -> next = second -> next;
                delete(second);
                second = temp;
            } else {
                first = first -> next;
                second = second -> next;
            }
        }
        return head;
    }
};