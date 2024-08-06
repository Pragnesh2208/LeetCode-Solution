/***********************Optimal Approach for Top  view of Binary Tree**************/
/************************Time Complexity = O(N*logn)***************************************************/
/************************Space Complexity = O(N)**************************************************/

class Solution
{
    public:

  
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,int>mp;
        queue<pair<int,Node *>>que;
        que.push(make_pair(0 , root));
        while(!que.empty()) {
            int sz = que.size();
            while(sz--) {
                pair<int, Node *>pt = que.front();
                que.pop();
                if(mp.find(pt.first) == mp.end()) mp[pt.first] = pt.second -> data;
                if(pt.second -> left) que.push(make_pair(pt.first - 1 , pt.second -> left));
                if(pt.second -> right) que.push(make_pair(pt.first + 1 , pt.second -> right));
           }
        }
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
