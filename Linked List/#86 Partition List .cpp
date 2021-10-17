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
/********************Optimal approach to Partition List*******************************************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode * before = new ListNode (0);
       ListNode  * after =  new ListNode(0);
       ListNode * ptr1 = before , *ptr2 = after;
       while(head != NULL) {
           if(head -> val < x) {
               ptr1 -> next = head;
               ptr1 = ptr1 -> next;
           }
           else {
               ptr2 -> next = head;
               ptr2 = ptr2 -> next;
           }
           head = head -> next;
       }
        ptr2 -> next =NULL;
        ptr1 -> next = after -> next;
        return before -> next;
    }
};