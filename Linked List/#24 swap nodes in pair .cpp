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
/********************Optimal approach to swap nodes in pair in Linked List*********************/
/*******************Time complexity = O(N)*******************************************************/
/*******************Space complexity = O(1)*****************************************************/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = head;
        
        while(dummy != NULL && dummy -> next != NULL) {
            swap(dummy -> val , dummy -> next -> val);
            dummy = dummy -> next -> next;
        }
        return head;
    }
};