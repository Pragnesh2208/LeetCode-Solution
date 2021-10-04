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
/********************Brute Force approach to Convert Binary number in LinkedList into integer*********************/
/*******************Time complexity = O(N) ***********************************************/
/*******************Space complexity = O(1)  *********************************************/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode * Curr=head;
        long long j=-1;
        while(Curr!=NULL)
        {
            j++;
            Curr=Curr->next;
        }
        Curr=head;
        long long ans=0;
        while(Curr!=NULL)
        {
            ans+=(1<<j)*Curr->val;
            j--;
            Curr=Curr->next;
        }
        return ans;
    }
};
/********************Efficeint approach to Convert Binary number in LinkedList into integer*********************/
/*******************Time complexity = O(N) ***********************************************/
/*******************Space complexity = O(1)  *********************************************/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode * Curr=head;
        long long ans=0;
        while(Curr!=NULL)
        {
            ans=(2*ans)+Curr->val;
            Curr=Curr->next;
        }
       
        return ans;
    }
};