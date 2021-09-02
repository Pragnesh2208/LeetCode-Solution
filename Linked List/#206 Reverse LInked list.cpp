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

/********************Iterator approach To Reverse a linked list ******************************/
/*******************Time complexity = O(N) ***********************************************/
/*******************Space complexity = O(1)  ***********************************************/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
         
        if( head==NULL || head->next==NULL)
            return head;
        else{
           ListNode *Next=head->next, *prev=NULL , *curr=head;
           
            while(curr!=NULL)
            {Next=curr->next;
                curr->next=prev;
                prev=curr; 
                curr=Next;
               
            } 
        return prev;
    }
    }
    };