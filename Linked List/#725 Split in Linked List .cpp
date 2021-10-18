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
/********************Optimal approach to Split List*******************************************/
/*******************Time complexity = O(N) *******************************************************/
/*******************Space complexity = O(1)  *****************************************************/
class Solution {
public:
    int size(ListNode * head) {
        int size = 0;
        while(head != NULL) {
            head = head -> next;
            size++;
        }
        return size;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = size(head);
        int rem = len % k;
        int width = len / k;
        vector<ListNode *>answer;

       for(int i = 0 ; i< k ;i++ ) {
           answer.push_back(head);

           for(int j = 0 ; j < width + (i < rem ?1:0 ) - 1; j++ ) {
              
               if(head != NULL) {
                   head = head -> next;
               }
           }

           ListNode * next = NULL;

           if(head != NULL){
               next = head -> next;
               head -> next =NULL;
           }
           head = next;              
        }
        return answer;
    }
};