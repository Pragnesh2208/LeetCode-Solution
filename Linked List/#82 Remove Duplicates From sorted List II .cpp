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
/********************Optimal approach to Remove Duplicates From sorted Lists II *****************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * curr = new ListNode(0);
        ListNode * ptr1 = curr;
        while(head != NULL) {

            if( head -> next != NULL && head->val == head->next -> val) {
                while(head -> next!= NULL && head->val == head->next->val) {
                    head = head -> next;
                }
                ptr1 -> next= head -> next;
            }
            else {
                ptr1 -> next = head ;
                ptr1 = ptr1 -> next;
            }
            head = head -> next;
        }
        return curr -> next;
    }
};