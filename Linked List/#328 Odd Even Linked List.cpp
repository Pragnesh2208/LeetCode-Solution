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
/********************Optimal approach to Make Odd Even Linked List*********************/
/*******************Time complexity = O(N)*******************************************************/
/*******************Space complexity = O(1)*****************************************************/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode * ptr1 =head;
        ListNode * ptr2 = head -> next;
        ListNode * curr = ptr2;
        while(ptr2 !=NULL && ptr2 -> next !=NULL)
        {
            ptr1 -> next = ptr2 -> next;
            ptr1 = ptr1 -> next ;
            ptr2 -> next = ptr1 ->next;
            ptr2 = ptr2 -> next;
        }
        ptr1 -> next = curr;
        return head;
        
    }
};

/*
Clean Code
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode * odd = new ListNode(0) , * even = new ListNode(0);
        vector<ListNode *> tail = {odd , even};
        bool isOdd = false;
        for(auto itr = head ; itr != NULL ; itr = itr -> next) {
            tail[isOdd] -> next = itr;
            tail[isOdd] = tail[isOdd] -> next;
            isOdd = !isOdd;            
        }
        tail[1] -> next = NULL;
        tail[0] -> next = even -> next;
        return odd -> next;
    }
};