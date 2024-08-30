/***********************Optimal Approach for Children Sum in Binary Tree**************/
/************************Time Complexity = O(N)***************************************/
/************************Space Complexity = O(N)**************************************/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
        if(root == NULL) return 1;
        int left = 0 ,right = 0;
        if(root -> right) right = isSumProperty(root -> right);
        if(root -> left) left = isSumProperty(root -> left);
         
        if((root -> right && right == 0) ||( root -> left && left == 0)) return 0;
        if(root -> right == NULL && root -> left == NULL) return 1;
        
        if(root -> right == NULL ) return root -> left -> data == root -> data;
        else if(root -> left == NULL) return root -> right -> data == root -> data;
        
        return root -> right -> data + root -> left -> data == root -> data;
    }
};
