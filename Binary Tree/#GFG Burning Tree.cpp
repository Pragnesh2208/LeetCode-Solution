/***********************Optimal Approach for Burning Tree**************/
/************************Time Complexity = O(NLogN)***************************************/
/************************Space Complexity = O(N)**************************************/
class Solution {
    private: Node * targetNode;
  public:
    void inorder(Node * root , map<Node * , Node *>&mp , int target) {
        if(!root) return;
        if(target == root -> data) this -> targetNode = root;
        if(root -> left) {
            mp[root -> left ] = root;
            inorder(root -> left , mp , target);
        }
        
        if(root -> right) {
            mp[root -> right] = root;
            inorder(root -> right  , mp , target);
        }
        
        return;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node * , Node *>mp;
        
        inorder(root , mp , target);
        
        map<Node * , bool> visit;
        queue<Node *>que;
        
        que.push(this -> targetNode);
        int ans = 0;
        while(!que.empty()) {
            ans++;
            int sz = que.size();
            while(sz--) {
                Node * top = que.front();
                que.pop();
                if(visit[top]) continue;
                visit[top] = true;
                if(top != root && !visit[mp[top]]) {
                    que.push(mp[top]);
                }
                
                if(top -> left && !visit[top -> left]) {
                    que.push(top -> left);
                }
                
                if(top -> right && !visit[top -> right]) {
                    que.push(top -> right);
                }
            }
        }
        return ans - 1;
    }
};
