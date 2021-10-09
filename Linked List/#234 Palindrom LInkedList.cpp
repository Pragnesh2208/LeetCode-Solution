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
/********************Optimal approach to Check is given Linked List is palindrom or not*********************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/

class Solution {
public:
    ListNode * reverse(ListNode *head)
    {
        ListNode * curr = head;
        ListNode * prev = NULL;
         ListNode * next = NULL;
        while(curr!=NULL)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next ;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * ptr1 = head , *ptr2 = head;
        while(ptr2 ->next !=NULL && ptr2 -> next ->next !=NULL)
        {
            ptr2 = ptr2 -> next ->next;
            ptr1 = ptr1 -> next;
        }
        ptr1 -> next = reverse(ptr1 -> next );
        ptr2 = ptr1 -> next;
        ptr1 = head;
        while(ptr2!=NULL)
        {
            if(ptr1->val != ptr2 -> val)
                return false;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return true;
        
    }
};