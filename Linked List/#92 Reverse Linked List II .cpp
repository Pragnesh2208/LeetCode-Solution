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
/********************Optimal approach to Reverse Linked List*********************/
/*******************Time complexity = O(N)*******************************************************/
/*******************Space complexity = O(1)*****************************************************/
class Solution {
public:
    ListNode * reverse ( ListNode * head) {
        ListNode * prev = NULL;
        while(head != NULL) {
            ListNode * Next= head -> next;
            head -> next = prev;
            prev = head;
            head = Next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * ptr1 = head , * ptr2 = head , * prev = NULL;
        int diff = right - left ;
        left--;
        while(diff > 0) {
            ptr2 = ptr2 -> next;
            diff--;
        }
        while( left > 0) {
            prev = ptr1;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
            left--;
        }
        
        ListNode * Next1 = ptr1;
        ListNode * Next2 =  ptr2->next;
        ptr2 -> next = NULL;
        ptr1 = reverse(ptr1);
        Next1 -> next = Next2;
        if(prev!= NULL)
        prev -> next = ptr1 ;
        else
            head= ptr1;
        return head;
    }
};