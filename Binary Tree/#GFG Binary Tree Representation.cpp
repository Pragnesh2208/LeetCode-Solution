/*
* Optimal solution
* Time Complexity = O(1)
* Space Complexity = O(1)
*/
class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        queue<node*>q;
        int i = 1 , n = vec.size();
        q.push(root0);
        
        while(!q.empty()) {
            node * root = q.front();
            q.pop();
            if(root == NULL) continue;
            
            struct node *leftNode = i < n ? newNode(vec[i]) : NULL;
            
            root -> left = leftNode;
            q.push(leftNode);
            i++;
            struct node *rightNode = i < n ? newNode( vec[i] ) : NULL; 
            root -> right = rightNode;
            q.push(rightNode);
            i++;
        }
    }

};