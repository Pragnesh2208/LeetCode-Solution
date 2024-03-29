/*
Brute Force Approach
Time Complexity = O(N)
Space Complexity = O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * subHead = node -> next;

        while(subHead -> next != NULL) {
            node -> val = subHead -> val;
            node = node -> next;
            subHead = subHead -> next;
        }
        node -> val = subHead -> val;
        node -> next = NULL;

        return ;
    }
};

/*
Optimal Approach to Delete Node
Time Complexity = O(1)
Space Complexity = O(1)
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
        
        return ;
    }
};