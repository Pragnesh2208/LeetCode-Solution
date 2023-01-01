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

/************************Optimal solution to Sort a Linked List*************************/
/************************Time Complexity = O(N*LogN)**************************************************/
/************************Space Complexity = O(1)*************************************************/

class Solution {
    ListNode * mergeList(ListNode *l1 , ListNode *l2) {
              
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *p1  ;
       
        p1 = l1->val > l2-> val ? l2  : l1;
  
        ListNode * d = new ListNode(-1);
        d -> next = p1;
        if(l1 -> val > l2 -> val) l2 = l2 -> next;
        else l1 = l1 -> next;

        while(l1 != NULL && l2 != NULL) {
           
            if(l1 -> val > l2 -> val) {
                p1->next = l2;
              
                l2 = l2 -> next;
            }
               
            else  {
                p1 -> next = l1;
               l1 =  l1 -> next;
            }
              p1 = p1 -> next;
        }

        while(l1 != NULL) {
            p1 -> next = l1;
          p1 = p1 -> next;
            l1 = l1 -> next;
        }

        while(l2 != NULL) {
            p1 -> next = l2;
              p1 = p1 -> next;
            l2 = l2 -> next;
        }
        return d -> next;
    }

    ListNode * mergesortList(ListNode * head) {
        if(head -> next == NULL) return head;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        } 
        ListNode * temp = slow -> next;
        slow -> next = NULL;
        slow = temp;

        ListNode * l1 = mergesortList(head);
        ListNode * l2 = mergesortList(slow);
      
        return mergeList(l1 , l2);
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
     return mergesortList(head);   
    }
};