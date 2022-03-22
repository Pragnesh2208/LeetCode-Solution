/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/*********************Brute Force Approach Using BFS for Populating Next Pointers in Each Node**/
/*********************Time complexity = O (N)**************************************************/
/**********************Space complexity = O (N)************************************************/
class Solution {
    void bfs(Node * root) {
        if(root == NULL)
            return;
        queue<Node *  > que;
      
        que.push(root );
        while(!que.empty()) {
            
            int size = que.size();
            while(size--) {
             Node * temp = que.front();
            que.pop();
                if(size)
            temp -> next = que.front();
                else
                    temp -> next = NULL;
                if(temp -> left) {
            que.push(temp -> left);
            que.push(temp -> right); }
        
            }
        }   
    }
public:
    Node* connect(Node* root) {
        
     bfs(root );   
        return root;
    }
};
/*********************Optimal Approch for Populating Next Pointers in Each Node****************/
/*********************Time complexity = O (N)**************************************************/
/**********************Space complexity = O (1)************************************************/

class Solution {
    void bfs(Node * root) {
        if(root == NULL)
            return;
        while(root) {
            if(root -> left) {
                for(Node * cur = root ; cur ; cur = cur -> next) {
                    
                    cur -> left -> next = cur -> right;
                    if(cur -> next)
                    cur -> right -> next = cur -> next -> left;
                }   
            }
            else
                break;
            root = root -> left;
             
        }
    }
public:
    Node* connect(Node* root) {
        
     bfs(root );   
        return root;
    }
};