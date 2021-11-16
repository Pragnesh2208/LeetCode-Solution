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
/********************Optimal approach to Reverse Node in k Group*******************************************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    int Lenghth(ListNode * head) { 
        int len = 0;
         while(head) {
            len++;
            head= head -> next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy  = new ListNode(0);
        dummy -> next = head;
        ListNode * curr =  dummy , * nex = dummy , *pre = dummy;
        int len = Length(head);
        while(len >=k) {
            curr = pre -> next;
            nex = curr -> next;
            for(int i = 1 ; i  < k ;  i++) {
                curr -> next = nex -> next;
                nex -> next = pre -> next;
                pre -> next = nex;
                nex = curr -> next;
            }
            pre = curr;
            len -=k;
        }
        return dummy -> next;
    }
};