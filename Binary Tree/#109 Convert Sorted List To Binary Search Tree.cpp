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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*********************Optimal Approch for Convert Sorted List to Binary Search Tree****************/
/*********************Time complexity = O (NLogN)**************************************************/
/**********************Space complexity = O (H)****************************************************/
class Solution {
    TreeNode *ConstructTree(ListNode * head , ListNode *end) {
        if(head == NULL || end == NULL || (head -> val > end->val))
            return NULL;
        
        ListNode *prev = NULL, *forward;
        ListNode *slow=head , *fast= head;
        cout<<head ->val<<" ";
        while(fast!=end && fast -> next !=end ) {
            
            prev = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
            
        }   
        cout<<slow->val<<endl;
        forward = slow -> next;
        ListNode * middle =  slow;
        
        TreeNode * root = new TreeNode(middle -> val);
        
        root -> left = ConstructTree(head , prev );
        root ->right = ConstructTree(forward , end);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode * cur = head;
        while(cur -> next != NULL)
            cur = cur -> next;
        return ConstructTree(head ,cur);
    }
};