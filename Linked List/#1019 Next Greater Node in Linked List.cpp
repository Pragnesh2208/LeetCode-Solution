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
/********************Optimal approach to Find Next Greater Node in Linked List*********************/
/*******************Time complexity = O(N)*******************************************************/
/*******************Space complexity = O(N)*****************************************************/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
      vector<int> ans;
        stack<int>st;
  for (auto p = head; p != nullptr; p = p->next)
      ans.push_back(p->val);
  for (int i = ans.size() - 1; i >= 0; --i) {
    int val = ans[i];
    while (!st.empty() && st.top() <= ans[i])
        st.pop();
    ans[i] = st.empty() ? 0 : st.top();
    st.push(val);
  }
  return ans;
    }
};

/********************Optimal approach to Find Next Greater Node in Linked List by traversing linkedlist******/
/*******************Time complexity = O(N)*******************************************************************/
/*******************Space complexity = O(N)******************************************************************/
class Solution {
    private:
    ListNode* reverseList(ListNode *head) {
        ListNode dh = ListNode(0);
        dh.next = head;
        while(head -> next) {
            ListNode * currNext = head -> next;
            ListNode * tempNext = currNext -> next;
            currNext -> next = dh.next;
            dh.next = currNext;
            head -> next = tempNext;
        }

        return dh.next;
    }

    int getLength(ListNode * head) {
        int count = 0 ;
        while(head) {head = head -> next;
        count++;};
        return count;
    }

public:
    vector<int> nextLargerNodes(ListNode* head) {
        int len = getLength(head);
        vector<int>ans(len , 0);
        stack<int>st;
        head = reverseList(head);
        int index = len - 1;
        while(head) {
            while(st.size() > 0 && st.top() <= head -> val) {
                st.pop();
            }

            if(st.size() == 0) {
                ans[index] = 0;
            } else {
                ans[index] = st.top();
            }

            index--;
            st.push(head -> val);
            head = head -> next;
        }

        return ans;
    }
};