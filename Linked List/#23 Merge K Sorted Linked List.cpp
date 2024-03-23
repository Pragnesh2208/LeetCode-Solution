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

/*
* Optimal Approach to solve merge K Sorted Linked List using Divide and Conquer Approach
Time Complexity = O(N LogK)
Space Complexity = O(N)
Auxilary Space Complexity = O(LogK)
Here N is number of node in list and K is number of list
*/
class Solution {
    ListNode * mergeTwoList(ListNode * l1 , ListNode * l2) {
        ListNode * dummy = new ListNode(0);
        ListNode * tail = dummy;
        while(l1 && l2) {
            if(l1 -> val < l2 -> val) {
                tail -> next = l1;
                tail = tail -> next;
                l1 = l1 -> next;
            } else {
                tail -> next = l2;
                tail = tail -> next;
                l2 = l2 -> next;
            }
        }
        if(l1) tail -> next = l1;
        if(l2) tail -> next = l2;
        return dummy -> next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() <= 1)
            return lists.size() == 1 ? lists[0] : NULL;
        int n = lists.size();
        vector<ListNode *> mergedList;
        for(int i = 0 ; i < n ; i+= 2) {
            if(i + 1 < n)
            mergedList.push_back(mergeTwoList(lists[i] , lists[i + 1]));
            else mergedList.push_back(lists[i]);
        }
        return mergeKLists(mergedList);
    }
};


/*
 Optimal Approach to solve merge K Sorted Linked List using Heap
Time Complexity = O(N LogK)
Space Complexity = O(K)
Auxilary Space Complexity = O(1)
Here N is number of node in list and K is number of list
*/
 class MyComp{
    public: 
    bool operator()(ListNode * a , ListNode* b) {
        return a -> val > b -> val;
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode* , vector<ListNode*>, MyComp>pq;
       int k = lists.size();
       ListNode * head = new ListNode(0);
       ListNode * tail = head;

       for(int i = 0 ; i < k ; i++) {
            if(lists[i] != NULL)
            pq.push(lists[i]);
       }

       while(!pq.empty()) {
            ListNode * minEle = pq.top();
            pq.pop();

            tail -> next = minEle;
            ListNode *tempNext = minEle -> next;
            if(tempNext) pq.push(tempNext);

            minEle -> next = nullptr;
            tail = tail -> next;
       }
        return  head -> next;
    }
};