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
/********************Optimal approach to Merge in between Linked List*********************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * ptr1 =NULL;
        ListNode * ptr2= list1;
        ListNode * curr= list2;
        
        for(int i=1 ; i< a ;i++)
            ptr2 = ptr2 -> next;

        ptr1 = ptr2;
        
        for(int i = a ; i<=b ; i++)
            ptr2 = ptr2 ->next;
        
        while(curr->next!=NULL)
            curr= curr->next;
        
         ptr1 -> next =list2;
        curr -> next =ptr2 ->next;
        
        return list1;
    }
};