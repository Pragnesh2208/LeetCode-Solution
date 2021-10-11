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