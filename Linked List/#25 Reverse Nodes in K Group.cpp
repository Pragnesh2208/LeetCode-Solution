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
/*
Clean Code
*/
class Solution {
    ListNode * reverse(ListNode * head , int k){
        ListNode * subHead = head -> next;
        ListNode * dummy = subHead;
        int cnt = k + 1;
        while(cnt && dummy != NULL) {
            dummy = dummy -> next;
            cnt--;
        }
        if(cnt) return head;
        while(k--) {
            ListNode *curNext = subHead -> next;
            subHead -> next = curNext -> next;
            curNext -> next = head -> next;
            head -> next = curNext;
        }
        ListNode * x = subHead;
        while(x != NULL){ cout<<x->val<<"->";
        x = x -> next;
        }
        cout<<endl;
        return subHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummyHead = new ListNode(-1);
        ListNode * tail = dummyHead;
        dummyHead -> next = head;
        while(tail -> next != NULL) {
            ListNode * temp =  reverse(tail , k - 1);
            if(temp == tail) break;
            else tail = temp;
        }
        return dummyHead -> next;
    }
};