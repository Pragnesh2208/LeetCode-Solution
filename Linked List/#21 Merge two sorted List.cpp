
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

/********************Optimal approach to Merge two sorted Linked List*********************/
/*******************Time complexity = O(N) ***********************************************/
/*******************Space complexity = O(1)  *********************************************/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *answer = new ListNode(1);
        ListNode *pre=answer ,*dl1=l1,*dl2=l2;
        while(dl1!=NULL && dl2!=NULL)
        {
            if(dl1->val > dl2->val){
                pre->next=dl2;
                dl2=dl2->next;   
            }
            else
            {
              pre->next=dl1;
                dl1=dl1->next;  
            }
            pre=pre->next;
        }
        pre->next=(dl1!=NULL)?dl1:dl2;
        return answer->next; 
    }
};